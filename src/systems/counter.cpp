#include "counter.h"
#include <raylib.h>
#include <format>

void CounterSystem::init() {
    this->state->counters = {};
    this->texture = LoadTexture("../assets/timer.png");
    this->state->is_paused = false;
    this->state->remaining_counters = 0;
}

void CounterSystem::tick() {
    if (this->state->player_baked) {
        this->state->counters = {};
        this->state->remaining_counters = 0;
        this->state->triggered_counters = {};
        this->state->waiting_counters = {};
        this->state->is_paused = false;
        return;
    }
    for (Counter& counter : this->state->waiting_counters) {
        this->state->counters.push_back(counter);
        this->state->remaining_counters++;
    }
    this->state->waiting_counters.clear();
    
    for (size_t i = 0; i < this->state->counters.size(); i++) {
        if (IsKeyPressed(KEY_ONE + i)) {
            this->state->is_paused = false;
            if (this->state->counters[i].paused) {
                this->state->counters[i].paused = false;
                break;
            }
            for (size_t j = 0; j < this->state->counters.size(); j++) {
                this->state->counters[j].paused = j == i;
                if (this->state->counters[j].paused) {
                    this->state->paused_color = this->state->counters[j].color;
                    this->state->is_paused = true;
                }
            }
        }
    }
    for (Counter &counter : this->state->counters) {
        counter.tick();
        if (counter.remaining_seconds < 0) {
            this->state->triggered_counters.emplace_back(counter.color);
            this->state->remaining_counters--;
            if (counter.paused) {
                this->state->is_paused = false;
            }
        }
    }
    std::erase_if(this->state->counters, [](const Counter& counter) {
        return counter.remaining_seconds < 0;
    });
}

void CounterSystem::after_draw() {
    const int SCALE = 16;
    const int FONT_SIZE = 120;

    for (size_t i = 0; i < this->state->counters.size(); i++) {
        Counter counter = this->state->counters[i];
        float x_offset = i * SCALE * this->texture.width;
        DrawRectangle(
            x_offset,
            this->texture.height * SCALE / 2.0f,
            this->texture.width * SCALE,
            this->texture.height * SCALE / 2,
            obstacle_color_to_raylib(counter.color)
        );
        DrawTextureEx(this->texture, { x_offset, 0 }, 0.0f, SCALE, WHITE);
        std::string text = std::format("{:01.1f}", counter.remaining_seconds);
        int width = MeasureText(text.c_str(), FONT_SIZE);
        DrawText(text.c_str(), x_offset + this->texture.width*SCALE/2.0f-width/2.0f, this->texture.height*SCALE/4.0f-32.0f, FONT_SIZE, WHITE);
    }
}

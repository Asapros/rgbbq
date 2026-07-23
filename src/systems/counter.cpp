#include "counter.h"
#include <raylib.h>
#include <format>

void CounterSystem::init() {
    this->counters = {};
    this->texture = LoadTexture("../assets/timer.png");
}

void CounterSystem::tick() {
    for (Counter& counter : this->state->waiting_counters) {
        this->counters.push_back(counter);
    }
    this->state->waiting_counters.clear();
    
    for (size_t i = 0; i < this->counters.size(); i++) {
        if (IsKeyPressed(KEY_ONE + i)) {
            if (this->counters[i].paused) {
                this->counters[i].paused = false;
                break;
            }
            for (size_t j = 0; j < this->counters.size(); j++) {
                this->counters[j].paused = j == i;
            }
        }
    }
    for (Counter &counter : this->counters) {
        counter.tick();
        if (counter.remaining_seconds < 0) {
            this->state->triggered_counters.emplace_back(counter.color);
        }
    }
    std::erase_if(this->counters, [](const Counter& counter) {
        return counter.remaining_seconds < 0;
    });
}

void CounterSystem::after_draw() {
    const int SCALE = 16;
    const int FONT_SIZE = 120;

    for (size_t i = 0; i < this->counters.size(); i++) {
        Counter counter = this->counters[i];
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

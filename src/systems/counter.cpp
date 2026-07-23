#include "counter.h"
#include <raylib.h>
#include <format>

void CounterSystem::init() {
    this->counters = {};
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
    const int COUNTER_HEIGHT = 400;
    const int COUNTER_WIDTH = 400;
    const int GAP = 200;

    for (size_t i = 0; i < this->counters.size(); i++) {
        Counter counter = this->counters[i];
        float x_offset = (COUNTER_WIDTH + GAP) * i;
        DrawRectangle(x_offset, 0, COUNTER_WIDTH, COUNTER_HEIGHT, GRAY);
        DrawRectangle(x_offset, COUNTER_HEIGHT/2, COUNTER_WIDTH, COUNTER_HEIGHT/2, obstacle_color_to_raylib(counter.color));
        DrawText(std::format("{:04.1f}", counter.remaining_seconds).c_str(), 50 + x_offset, 50, 150, BLACK);
    }
}

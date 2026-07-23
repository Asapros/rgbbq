#include "counter.h"

Counter::Counter(ObstacleColor color, float seconds) {
    this->color = color;
    this->remaining_seconds = seconds;
    this->paused = false;
}

void Counter::tick() {
    if (!this->paused) {
        this->remaining_seconds -= GetFrameTime();
    }
}


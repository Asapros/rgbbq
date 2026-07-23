#include "level.h"
#include <raylib.h>


void LevelSystem::init() {
    this->state->player_baked = false;
    this->state->waiting_counters = {
        Counter{ObstacleColor::Red, 2.0f},
        Counter{ObstacleColor::Green, 2.0f},
        Counter{ObstacleColor::Blue, 5.0f},
        Counter{ObstacleColor::Yellow, 5.0f}
    };
    this->state->waiting_obstacles = {
        Obstacle{1.0f, ObstacleColor::Red, {0, 0}, {1000, 500}, false},
        Obstacle{1.0f, ObstacleColor::Green, {0, 500}, {1000, 500}, false},
        Obstacle{1.0f, ObstacleColor::Blue, {0, 0}, {500, 1000}, false},
        Obstacle{1.0f, ObstacleColor::Yellow, {500, 0}, {500, 1000}, false}
    };
}

void LevelSystem::tick() {
    
}

void LevelSystem::after_draw() {
    if (this->state->player_baked) {
        DrawText("You got baked", GetScreenWidth() / 2, GetScreenHeight() / 2, 200, RED);
    }
}

#include "level.h"
#include <raylib.h>


void LevelSystem::init() {
    this->state->player_baked = false;
    this->state->waiting_counters = {
        Counter{ObstacleColor::Red, 5.0f},
        Counter{ObstacleColor::Green, 5.0f},
        Counter{ObstacleColor::Blue, 5.0f},
    };
    this->state->waiting_obstacles = {
        Obstacle{1.0f, ObstacleColor::Red, {0, 0}, {160*5, 160*10}, false},
        Obstacle{1.0f, ObstacleColor::Green, {160*5, 160*0}, {160*5, 160*10}, false},
    };
}

void LevelSystem::tick() {
    
}

void LevelSystem::after_draw() {
    if (this->state->player_baked) {
        DrawText("You got baked", GetScreenWidth() / 2, GetScreenHeight() / 2, 200, RED);
    }
}

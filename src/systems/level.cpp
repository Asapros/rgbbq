#include "level.h"
#include <raylib.h>


void LevelSystem::init() {
    this->level = 1;
    this->stage = 0;
    this->state->player_baked = false;
}

void LevelSystem::tick() {
    switch (this->level) {
        case 1:
            switch (this->stage) {
                case 0:
                    this->state->waiting_counters = {
                        Counter{ObstacleColor::Red, 5.0f},
                        Counter{ObstacleColor::Green, 5.0f},
                    };
                    this->state->waiting_obstacles = {
                        Obstacle{1.0f, ObstacleColor::Red, {0, 0}, {160*5, 160*10}, false},
                        Obstacle{1.0f, ObstacleColor::Green, {160*5, 160*0}, {160*5, 160*10}, false},
                    };
                    stage++;
                    break;
                case 1:
                    if (this->state->remaining_obstacles == 0) stage++;
                    break;
                case 2:
                    this->state->waiting_counters = {
                        Counter{ObstacleColor::Green, 5.0f},
                        Counter{ObstacleColor::Blue, 5.0f},
                    };
                    this->state->waiting_obstacles = {
                        Obstacle{1.0f, ObstacleColor::Green, {0, 0}, {160*10, 160*5}, false},
                        Obstacle{1.0f, ObstacleColor::Blue, {0, 160*5}, {160*10, 160*5}, false},
                    };
                    stage++;
                    break;
            }
    }
}

void LevelSystem::after_draw() {
    if (this->state->player_baked) {
        DrawText("You got baked", GetScreenWidth() / 2, GetScreenHeight() / 2, 200, RED);
    }
}

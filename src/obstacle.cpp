#include "obstacle.h"
#include "obstacle_template.h"
#include <raylib.h>

void ObstacleSystem::init() {
    this->obstacles = {
        Obstacle{1.0f, ObstacleColor::Red, {0,0}, {200, 200}, false},
        Obstacle{1.0f, ObstacleColor::Green, {400,0}, {100, 400}, false},
        Obstacle{1.0f, ObstacleColor::Blue, {500,500}, {200, 200}, false},
    };
}

void ObstacleSystem::tick() {
    for (ObstacleColor color : this->state->triggered_counters) {
        for (Obstacle& incoming : this->obstacles) {
            if (incoming.triggered || incoming.color != color) { continue; }
            incoming.triggered = true;
        }
    }
    this->state->triggered_counters.clear();
    for (Obstacle &obstacle : this->obstacles) {
        if (!obstacle.triggered) { continue; }
        obstacle.remaining_seconds -= GetFrameTime();
    }
    std::erase_if(this->obstacles, [](const Obstacle& obstacle) {
        return obstacle.triggered && obstacle.remaining_seconds < 0;
    });
}

void ObstacleSystem::draw() {
    for (Obstacle &obstacle : this->obstacles) {
        DrawRectangle(
            obstacle.position.x,
            obstacle.position.y,
            obstacle.area_of_effect.x,
            obstacle.area_of_effect.y,
            Fade(obstacle_color_to_raylib(obstacle.color), obstacle.triggered ? 1.0f : 0.5f)
        );
    }
}

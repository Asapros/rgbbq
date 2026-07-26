#include "obstacle.h"
#include <raylib.h>

void ObstacleSystem::init() {
    this->obstacles = {};
    this->state->remaining_obstacles = 0;
    this->death_sound = LoadSound("assets/death.wav");
}

const int MARGIN = 0;

void ObstacleSystem::tick() {
    if (this->state->player_baked) {
        this->obstacles = {};
        this->state->remaining_obstacles = 0;
        this->state->waiting_obstacles = {};
        return;
    }
    for (Obstacle& obstacle : this->state->waiting_obstacles) {
        this->obstacles.push_back(obstacle);
        this->state->remaining_obstacles++;
    }
    this->state->waiting_obstacles.clear();

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
        if (obstacle.remaining_seconds < 0) {
            this->state->remaining_obstacles -= 1;
        }
    }
    std::erase_if(this->obstacles, [](const Obstacle& obstacle) {
        return obstacle.triggered && obstacle.remaining_seconds < 0;
    });

    for (Obstacle &obstacle : this->obstacles) {
        if (
            obstacle.triggered
            && this->state->player_position.x > obstacle.position.x - MARGIN
            && this->state->player_position.x < obstacle.position.x + obstacle.area_of_effect.x + MARGIN
            && this->state->player_position.y > obstacle.position.y - MARGIN
            && this->state->player_position.y < obstacle.position.y + obstacle.area_of_effect.y + MARGIN
           ) {
            PlaySound(this->death_sound);
            this->state->player_baked = true;
        }
    }
}

void ObstacleSystem::draw() {
    BeginBlendMode(BLEND_ADDITIVE);
    for (Obstacle &obstacle : this->obstacles) {
        DrawRectangle(
            obstacle.position.x,
            obstacle.position.y,
            obstacle.area_of_effect.x,
            obstacle.area_of_effect.y,
            Fade(obstacle_color_to_raylib(obstacle.color), obstacle.triggered ? 1.0f : 0.6f)
        );
    }
    EndBlendMode();
}

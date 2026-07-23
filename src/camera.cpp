#include "camera.h"
#include <iostream>
#include <raylib.h>

void CameraSystem::init() {
    this->camera = Camera2D();
    this->camera.zoom = 1;
    this->camera.offset = { 0, 0 };
    this->camera.target = { 0, 0 };
    this->state->player_position = { 0, 0 };
}

void CameraSystem::tick() {
    std::cout << this->state->player_position.x << "," << this->state->player_position.y << std::endl;
    this->camera.target = this->state->player_position;
}

void CameraSystem::before_draw() {
    BeginMode2D(this->camera);
}

void CameraSystem::after_draw() {
    EndMode2D();
}

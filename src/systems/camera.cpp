#include "camera.h"
#include <raylib.h>

void CameraSystem::init() {
    this->camera = Camera2D();
    this->camera.zoom = 0.4f;
    this->camera.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
    this->camera.target = { 0, 0 };
}

void CameraSystem::tick() {
    this->camera.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
    this->camera.target = this->state->player_position;
}

void CameraSystem::before_draw() {
    BeginMode2D(this->camera);
}

void CameraSystem::after_draw() {
    EndMode2D();
}

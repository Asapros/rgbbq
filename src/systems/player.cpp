#include "player.h"
#include <raylib.h>
#include <raymath.h>

void PlayerSystem::init() {
    this->state->player_position = { 0, 0 };
}
const float speed = 6.0;

void PlayerSystem::tick() {
    Vector2 velocity = { 0, 0 };

    if (IsKeyDown(KEY_RIGHT)) {
        velocity.x += 1;
    }
    if (IsKeyDown(KEY_LEFT)) {
        velocity.x -= 1;
    }
    if (IsKeyDown(KEY_DOWN)) {
        velocity.y += 1;
    }
    if (IsKeyDown(KEY_UP)) {
        velocity.y -= 1;
    }
    this->state->player_position += Vector2Normalize(velocity) * speed;
}

void PlayerSystem::draw() {
    DrawRectangle(
        this->state->player_position.x - 50,
        this->state->player_position.y - 50,
        100,
        100,
        YELLOW
    );
}

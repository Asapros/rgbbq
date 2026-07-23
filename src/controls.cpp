#include "controls.h"
#include <raylib.h>
#include <raymath.h>

const float speed = 3.0;

void ControlsSystem::tick() {
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

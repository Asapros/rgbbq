#include "controls.h"
#include <raylib.h>


void ControlsSystem::tick() {
    if (IsKeyDown(KEY_RIGHT)) {
        this->state->player_position.x += 1;
    }
    if (IsKeyDown(KEY_LEFT)) {
        this->state->player_position.x -= 1;
    }
    if (IsKeyDown(KEY_DOWN)) {
        this->state->player_position.y += 1;
    }
    if (IsKeyDown(KEY_UP)) {
        this->state->player_position.y -= 1;
    }
}

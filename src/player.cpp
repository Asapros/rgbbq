#include "player.h"
#include <raylib.h>

void PlayerSystem::init() {
    this->state->player_position = { 0, 0 };
}

void PlayerSystem::draw() {
    DrawRectangle(
        this->state->player_position.x,
        this->state->player_position.y,
        100,
        100,
        YELLOW
    );
}

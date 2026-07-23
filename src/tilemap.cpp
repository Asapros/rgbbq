#include "tilemap.h"
#include <raylib.h>

const int TILE_SIZE = 100;

void TilemapSystem::init() {
    this->state->ground_dimensions = { 10, 10 };
}

void TilemapSystem::draw() {
    for (int x = 0; x < this->state->ground_dimensions.x; x++) {
        for (int y = 0; y < this->state->ground_dimensions.y; y++) {
            DrawRectangle(
                x * TILE_SIZE,
                y * TILE_SIZE,
                TILE_SIZE,
                TILE_SIZE,
                (x + y) % 2 == 1 ? DARKGRAY : GRAY
            );
        }
    }
}

void TilemapSystem::tick() {
    this->state->player_position.x = std::min(std::max(this->state->player_position.x, 0.0f), (this->state->ground_dimensions.x - 1) * TILE_SIZE);
    this->state->player_position.y = std::min(std::max(this->state->player_position.y, 0.0f), (this->state->ground_dimensions.y- 1) * TILE_SIZE);
}

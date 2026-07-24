#include "tilemap.h"
#include <raylib.h>

const float TILE_SIZE = 160.0f;

void TilemapSystem::init() {
    this->state->ground_dimensions = { 10, 10 };
    this->grillTexture = LoadTexture("../assets/grill.png");
}

void TilemapSystem::draw() {
    for (int x = 0; x < this->state->ground_dimensions.x; x++) {
        for (int y = 0; y < this->state->ground_dimensions.y; y++) {
            DrawTextureEx(
                this->grillTexture,
                { x * TILE_SIZE, y * TILE_SIZE },
                0.0f,
                10.0f,
                WHITE
            );
        }
    }
}

void TilemapSystem::tick() {
    this->state->player_position.x = std::min(
        std::max(this->state->player_position.x, 0.0f),
        (this->state->ground_dimensions.x - 0.5f) * TILE_SIZE
    );
    this->state->player_position.y = std::min(
        std::max(this->state->player_position.y, -0.5f * TILE_SIZE),
        (this->state->ground_dimensions.y - 0.5f) * TILE_SIZE
    );
}

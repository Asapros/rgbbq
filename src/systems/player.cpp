#include "player.h"
#include <raylib.h>
#include <raymath.h>

void PlayerSystem::init() {
    this->state->player_position = { 0, 0 };
    this->player_textures[0] = LoadTexture("../assets/potato-0.png");
    this->player_textures[1] = LoadTexture("../assets/potato-1.png");
    this->player_textures[2] = LoadTexture("../assets/potato-2.png");
    this->player_textures[3] = LoadTexture("../assets/potato-3.png");
}
const float speed = 6.0;

void PlayerSystem::tick() {
    Vector2 velocity = { 0, 0 };
    bool moving = false;

    if (IsKeyDown(KEY_RIGHT)) {
        velocity.x += 1;
        moving = true;
        this->flip_sprite = true;
    }
    if (IsKeyDown(KEY_LEFT)) {
        velocity.x -= 1;
        moving = true;
        this->flip_sprite = false;
    }
    if (IsKeyDown(KEY_DOWN)) {
        velocity.y += 1;
        moving = true;
    }
    if (IsKeyDown(KEY_UP)) {
        velocity.y -= 1;
        moving = true;
    }
    this->state->player_position += Vector2Normalize(velocity) * speed;
    if (moving) {
        this->animation_timer = (this->animation_timer + (int)(GetFrameTime()*1000));
    }
}

void PlayerSystem::draw() {
    Texture2D texture = this->player_textures[(this->animation_timer / 100) % 4];

    Rectangle source = {
        0,
        0,
        (float)texture.width * (flip_sprite ? -1.0f : 1.0f),   // Negative width = horizontal mirror
        (float)texture.height
    };

    Rectangle dest = {
        this->state->player_position.x - 50,
        this->state->player_position.y - 50,
        (float)texture.width*10.0f,
        (float)texture.height*10.0f
    };

    DrawTexturePro(
        texture,
        source,
        dest,
        {0, 0},
        0.0f,
        WHITE
    );
}

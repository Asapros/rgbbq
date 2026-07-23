#pragma once

#include "system.h"
#include <raylib.h>
struct PlayerSystem : System {
    private:
        Texture2D player_textures[4];
        int animation_timer;
        bool flip_sprite;
    public:
    using System::System;

    void init() override;
    void tick() override;
    void draw() override;
};

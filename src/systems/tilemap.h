#pragma once

#include "system.h"

struct TilemapSystem : System {
    private:
    Texture2D grillTexture;
    Texture2D backgroundTexture;

    public:
    using System::System;

    void init() override;
    void tick() override;
    void draw() override;
};

#pragma once

#include "system.h"

struct TilemapSystem : System {
    private:
    Texture2D grillTexture;

    public:
    using System::System;

    void init() override;
    void tick() override;
    void draw() override;
};

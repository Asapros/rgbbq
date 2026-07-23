#pragma once

#include "system.h"

struct TilemapSystem : System {
    using System::System;

    void init() override;
    void tick() override;
    void draw() override;
};

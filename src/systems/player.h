#pragma once

#include "system.h"
struct PlayerSystem : System {
    using System::System;

    void init() override;
    void tick() override;
    void draw() override;
};

#pragma once

#include "system.h"
#include <raylib.h>

struct CounterSystem : System {
    private:
    Texture2D texture;

    public:
    using System::System;
    
    void init() override;
    void tick() override;
    void after_draw() override;
};

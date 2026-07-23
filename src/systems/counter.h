#pragma once

#include "system.h"
#include "../counter.h"
#include <raylib.h>
#include <vector>

struct CounterSystem : System {
    private:
    std::vector<Counter> counters;
    Texture2D texture;

    public:
    using System::System;
    
    void init() override;
    void tick() override;
    void after_draw() override;
};

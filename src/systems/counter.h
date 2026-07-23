#pragma once

#include "system.h"
#include "../counter.h"
#include <raylib.h>
#include <vector>

struct CounterSystem : System {
    private:
    std::vector<Counter> counters;

    public:
    using System::System;
    
    void init() override;
    void tick() override;
    void after_draw() override;
};

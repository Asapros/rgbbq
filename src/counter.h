#pragma once

#include "obstacle.h"
#include "system.h"
#include <raylib.h>
#include <vector>

struct Counter {
    float remaining_seconds;
    bool paused;
    ObstacleColor color;
    
    Counter(ObstacleColor color, float seconds);
    void tick();
};

struct CounterSystem : System {
    private:
    std::vector<Counter> counters;

    public:
    using System::System;
    
    void init() override;
    void tick() override;
    void after_draw() override;
};

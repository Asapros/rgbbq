#pragma once

#include "obstacle.h"

struct Counter {
    float remaining_seconds;
    bool paused;
    ObstacleColor color;
    
    Counter(ObstacleColor color, float seconds);
    void tick();
};


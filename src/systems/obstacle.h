#pragma once

#include "system.h"
#include "../obstacle.h"
#include <raylib.h>

struct ObstacleSystem : System {
    private:
    std::vector<Obstacle> obstacles;
    Sound death_sound;

    public:
    using System::System;

    void init() override;
    void tick() override;
    void draw() override;
};

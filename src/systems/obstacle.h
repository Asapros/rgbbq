#pragma once

#include "system.h"
#include "../obstacle.h"

struct ObstacleSystem : System {
    private:
    std::vector<Obstacle> obstacles;

    public:
    using System::System;

    void init() override;
    void tick() override;
    void draw() override;
};

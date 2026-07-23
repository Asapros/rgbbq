#pragma once

#include "obstacle_template.h"
#include "system.h"

struct Obstacle {
    float remaining_seconds;
    ObstacleColor color;
    Vector2 position;
    Vector2 area_of_effect;
    bool triggered;
};

struct ObstacleSystem : System {
    private:
    std::vector<Obstacle> obstacles;

    public:
    using System::System;

    void init() override;
    void tick() override;
    void draw() override;
};

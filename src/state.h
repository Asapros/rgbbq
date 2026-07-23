#pragma once

#include <raylib.h>
#include <vector>
#include "obstacle.h"
#include "counter.h"

struct GameState {
    Vector2 player_position;
    bool player_baked;
    Vector2 ground_dimensions;
    int remaining_obstacles;
    std::vector<ObstacleColor> triggered_counters;
    std::vector<Obstacle> waiting_obstacles;
    std::vector<Counter> waiting_counters;
};

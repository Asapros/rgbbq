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
    int remaining_counters;
    bool is_paused;
    ObstacleColor paused_color;
    std::vector<Counter> counters;
    std::vector<ObstacleColor> triggered_counters;
    std::vector<Obstacle> waiting_obstacles;
    std::vector<Counter> waiting_counters;
};

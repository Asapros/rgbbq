#pragma once

#include <raylib.h>
#include <vector>
#include "obstacle_color.h"

struct GameState {
    Vector2 player_position;
    Vector2 ground_dimensions;
    std::vector<ObstacleColor> triggered_counters;
};

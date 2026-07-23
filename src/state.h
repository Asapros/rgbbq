#pragma once

#include <raylib.h>
#include <vector>
#include "obstacle_color.h"

struct GameState {
    Vector2 player_position;
    std::vector<ObstacleColor> trigerred_counters;
};

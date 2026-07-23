#pragma once

#include <raylib.h>
enum class ObstacleColor {
    Red,
    Green,
    Blue,
    Yellow
};

constexpr Color obstacle_color_to_raylib(ObstacleColor color)
{
    switch (color)
    {
    case ObstacleColor::Red:   return GetColor(0xFF0000FF);
    case ObstacleColor::Green: return GetColor(0x00FF00FF);
    case ObstacleColor::Blue:  return GetColor(0x0000FFFF);
    case ObstacleColor::Yellow:  return GetColor(0xFFFF00FF);
    }

    return BLANK;
}

struct Obstacle {
    float remaining_seconds;
    ObstacleColor color;
    Vector2 position;
    Vector2 area_of_effect;
    bool triggered;
};


#pragma once

#include <raylib.h>
enum class ObstacleColor {
    Red,
    Green,
    Blue,
    Yellow,
    Magenta,
    Cyan
};

constexpr Color obstacle_color_to_raylib(ObstacleColor color)
{
    switch (color)
    {
    case ObstacleColor::Red:   return GetColor(0xFF0000FF);
    case ObstacleColor::Green: return GetColor(0x00FF00FF);
    case ObstacleColor::Blue:  return GetColor(0x0000FFFF);
    case ObstacleColor::Yellow:   return GetColor(0xFFFF00FF);
    case ObstacleColor::Magenta: return GetColor(0xFF00FFFF);
    case ObstacleColor::Cyan:  return GetColor(0x00FFFFFF);
    }

    return BLANK;
}

struct Obstacle {
    float remaining_seconds;
    ObstacleColor color;
    Vector2 position;
    Vector2 area_of_effect;
    bool triggered;

    Obstacle(Vector2 unit_position, Vector2 unit_aoe, ObstacleColor color);
};


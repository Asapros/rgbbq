#pragma once

#include <raylib.h>
enum class ObstacleColor {
    Red,
    Green,
    Blue
};

constexpr Color obstacle_color_to_raylib(ObstacleColor color)
{
    switch (color)
    {
    case ObstacleColor::Red:   return GetColor(0xFF0000FF);
    case ObstacleColor::Green: return GetColor(0x00FF00FF);
    case ObstacleColor::Blue:  return GetColor(0x0000FFFF);
    }

    return BLANK;
}

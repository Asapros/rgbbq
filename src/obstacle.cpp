#include "obstacle.h"
#include <raymath.h>

const float ACTIVE_DURATION = 0.5f;

Obstacle::Obstacle(Vector2 unit_position, Vector2 unit_aoe, ObstacleColor color) {
    this->remaining_seconds = ACTIVE_DURATION;
    this->color = color;
    this->position = Vector2Scale(unit_position, 160.0f);
    this->area_of_effect = Vector2Scale(unit_aoe, 160.0f);
    this->triggered = false;
}

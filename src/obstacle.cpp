#include "obstacle.h"

void ObstacleSystem::tick() {
    for (ObstacleColor color : this->state->trigerred_counters) {
        this->state->player_position.x += 100;
    }
    this->state->trigerred_counters.clear();
}

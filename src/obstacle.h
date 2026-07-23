#pragma once

#include "system.h"

struct ObstacleSystem : System {
    using System::System;

    void tick() override;
};

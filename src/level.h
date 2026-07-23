#pragma once

#include "system.h"


struct LevelSystem : System {
    using System::System;

    void init() override;
    void tick() override;
};

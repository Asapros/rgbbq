#pragma once

#include "system.h"

struct ControlsSystem : System {
    using System::System;

    void tick() override;
};

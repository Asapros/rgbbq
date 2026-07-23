#pragma once

#include "system.h"


struct LevelSystem : System {
    private:
        int level;
        int stage;
    public:
    using System::System;

    void init() override;
    void tick() override;
    void after_draw() override;
};

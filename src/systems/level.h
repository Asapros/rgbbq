#pragma once

#include "system.h"


struct LevelSystem : System {
    private:
        int level;
        int stage;
        float level_timer;
        int level_var_1;
        int level_var_2;
    public:
    using System::System;

    void init() override;
    void tick() override;
    void after_draw() override;
};

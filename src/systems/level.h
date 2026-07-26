#pragma once

#include "system.h"
#include <raylib.h>


struct LevelSystem : System {
    private:
        int level;
        int stage;
        float level_timer;
        int level_var_1;
        int level_var_2;
        Sound continue_sound;
    public:
    using System::System;

    void init() override;
    void tick() override;
    void after_draw() override;
};

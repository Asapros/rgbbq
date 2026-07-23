#pragma once

#include <raylib.h>
#include "system.h"

struct CameraSystem : System {
    using System::System;

    private:
    Camera2D camera;

    public:

    void init() override;
    void tick() override;
    void before_draw() override;
    void after_draw() override;
};

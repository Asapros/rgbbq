#pragma once

#include "camera.h"
#include "state.h"
#include <memory>
#include <raylib.h>
#include <vector>

struct Game {
    std::vector<std::unique_ptr<System>> systems;
    GameState state;

    Game();


    void init();
    void tick();
    void draw();
};


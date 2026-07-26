#include "game.h"
#include <raylib.h>
#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

Game game;

void UpdateDrawFrame(void);

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT);
#ifndef PLATFORM_WEB
    ToggleBorderlessWindowed();
    SetTargetFPS(0);
#endif
    InitWindow(1280, 720, "GMTK 2026");
    InitAudioDevice();
    
    game.init();
#if defined(PLATFORM_WEB)
    SetTargetFPS(144);
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    while (!WindowShouldClose()) {
        UpdateDrawFrame();
    }
#endif
    CloseAudioDevice();
    CloseWindow();

    return 0;
}

void UpdateDrawFrame() {
    BeginDrawing();
    ClearBackground(BLACK);
    
    game.tick();
    game.draw();

    EndDrawing();
}

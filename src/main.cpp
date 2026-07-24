#include "game.h"
#include <raylib.h>

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT);

    InitWindow(0, 0, "GMTK 2026");
    ToggleBorderlessWindowed();
    InitAudioDevice();

    SetTargetFPS(0);
    
    Game game;

    game.init();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        
        game.tick();
        game.draw();

        EndDrawing();
    }
    CloseAudioDevice();
    CloseWindow();

    return 0;
}

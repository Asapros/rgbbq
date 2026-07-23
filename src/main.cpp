#include <raylib.h>

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT);

    InitWindow(0, 0, "GMTK 2026");
    ToggleBorderlessWindowed();

    SetTargetFPS(0);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Hello, raylib2!", 20, 20, 30, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

#include <raylib.h>
#include "grid.cpp"
#define WINDOW_IS_OPEN !WindowShouldClose()
int main()
{
    InitWindow(300, 600, "Tetris");
    Grid grid = Grid();
    while (WINDOW_IS_OPEN)
    {
        BeginDrawing();
        ClearBackground({255,255,255,255});
        grid.Draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

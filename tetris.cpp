#include <raylib.h>
#include "grid.cpp"
#include "block.h"
#define WINDOW_IS_OPEN !WindowShouldClose()
int main()
{
    SBlock block;
    InitWindow(300, 600, "Tetris");
    Grid grid = Grid();
    while (WINDOW_IS_OPEN)
    {
        BeginDrawing();
        ClearBackground({255, 255, 255, 255});
        grid.Draw();
        block.draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

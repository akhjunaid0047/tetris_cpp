#include <raylib.h>
#include "block.h"
#include "game.h"
#define WINDOW_IS_OPEN !WindowShouldClose()
int main()
{
    Game game;
    InitWindow(300, 600, "Tetris");
    while (WINDOW_IS_OPEN)
    {
        BeginDrawing();
        ClearBackground({255, 255, 255, 255});
        game.draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

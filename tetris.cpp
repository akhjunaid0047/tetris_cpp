#include <raylib.h>
#include "block.h"
#include "game.h"
#define WINDOW_IS_OPEN !WindowShouldClose()

double lastMoveTime = 0;
int eventTriggered(double time)
{

    double currentTime = GetTime();
    if (currentTime - lastMoveTime >= time)
    {
        lastMoveTime = currentTime;
        return 1;
    }
    return 0;
}
int main()
{
    Game game;
    InitWindow(300, 600, "Tetris");
    while (WINDOW_IS_OPEN)
    {
        if (eventTriggered(0.8))
            game.moveDown();
        game.input();
        BeginDrawing();
        ClearBackground({255, 255, 255, 255});
        game.draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

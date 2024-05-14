#include <raylib.h>
#define IS_WINDOW_OPEN !WindowShouldClose()
int main()
{
    InitWindow(300,600,"Tetris");
    while(IS_WINDOW_OPEN)
    {
        BeginDrawing();
        // ClearBackground();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

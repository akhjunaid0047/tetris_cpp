#pragma once
#include <vector>
#include <raylib.h>
#include "colors.h"
class Grid
{
public:
    Grid();
    int grid[20][10];
    void initialise();
    void print();
    void Draw();
    int isCellOutside(int row, int column);
private:
    int rows, columns, cellsize;
    std::vector<Color> colors;
};
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
    int isCellEmpty(int row, int column);
    void clearCompletedRows();
private:
    int rows, columns, cellsize;
    std::vector<Color> colors;
    int isRowFull(int row);
    void clearRow(int row);
    void moveRowDown(int row, int number);
};
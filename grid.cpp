#include "grid.h"
#include "colors.h"
#include <iostream>
#include <raylib.h>
Grid::Grid()
{
    rows = 20;
    columns = 10;
    cellsize = 30;
    initialise();
    print();
    colors = getColour();
}

void Grid::initialise()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void Grid::print()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << grid[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void Grid::Draw()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            int cellValue = grid[i][j];
            DrawRectangle(j * cellsize, i * cellsize, cellsize - 1, cellsize - 1, colors[cellValue]);
        }
        std::cout << "\n";
    }
}
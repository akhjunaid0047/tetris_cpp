#include "grid.h"
#include <iostream>
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

std::vector<Color> Grid::getColour()
{
    Color darkgray = {26, 31, 40, 255};
    Color f94144 = {249, 65, 68, 255};
    Color f3722c = {243, 114, 44, 255};
    Color f8961e = {248, 150, 30, 255};
    Color f9c74f = {249, 199, 79, 255};
    Color n0be6d = {144, 190, 109, 255};
    Color f3aa8b = {67, 170, 139, 255};
    Color fi77590 = {87, 117, 144, 255};
    return {darkgray, f94144, f3722c, f8961e, f9c74f, n0be6d, f3aa8b, fi77590};
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
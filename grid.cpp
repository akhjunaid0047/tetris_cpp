#include "grid.h"
#include<iostream>
Grid::Grid()
{
    rows = 20;
    columns = 10;
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
            
        }
    }
}
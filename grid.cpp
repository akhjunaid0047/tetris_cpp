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

int Grid::isCellOutside(int row, int column)
{
    if ((rows > row and row >= 0) and (columns > column and column >= 0))
        return 0;
    return 1;
}

int Grid::isCellEmpty(int row, int column)
{
    if (!grid[row][column])
        return 1;
    return 0;
}

void Grid::clearCompletedRows()
{
    int completed = 0;
    for(int r = rows-1;r>=0;r--){
        if(isRowFull(r))
        {
            clearRow(r);
            completed++;
        }
        else if(completed>0)
        {
            moveRowDown(r,completed);
        }
    }
}

int Grid::isRowFull(int row)
{
    for (int i = 0; i < columns; i++)
    {
        if (grid[row][i] == 0)
            return 0;
    }
    return 1;
}

void Grid::clearRow(int row)
{
    for (int i = 0; i < columns; i++)
        grid[row][i] = 0;
}

void Grid::moveRowDown(int row, int number)
{
    for (int i = 0; i < columns; i++)
    {
        grid[row + number][i] = grid[row][i];
        grid[row][i] = 0;
    }
}

#pragma once
#include <vector>
class Grid
{
public:
    Grid();
    int grid[20][10];
    void initialise();
    void print();
    void Draw();
private:
    int rows, columns, cellsize;
    std::vector<Color> getColour();
    std::vector<Color> colors;
};
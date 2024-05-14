#pragma once
class Grid
{
public:
    Grid();
    int grid[20][10];
    void initialise();
    void print();
private:
    int rows, columns;
};
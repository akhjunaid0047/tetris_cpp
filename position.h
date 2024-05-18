#pragma once
class Position
{
public:
    Position(int row, int column)
    {
        this->row = row;
        this->column = column;
    };
    int row, column;
};
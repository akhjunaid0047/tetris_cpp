#pragma once
#include <map>
#include <vector>
#include "position.h"
#include "colors.h"
#include <raylib.h>
class Block
{
    int cellsize, state;
    std::vector<Color> colors;

public:
    Block()
    {
        cellsize = 30;
        colors = getColour();
        state = 0;
        rowOffset = 0;
        columnOffset = 0;
    };
    int colorId, rowOffset, columnOffset;
    std::map<int, std::vector<Position>> rotationState;
    void draw()
    {
        std::vector<Position> currentPostion = getCurrentPosition();
        for (auto it : currentPostion)
        {
            DrawRectangle(it.column * cellsize, it.row * cellsize, cellsize - 1, cellsize - 1, colors[colorId]);
        }
    }
    void move(int row, int column)
    {
        rowOffset += row;
        columnOffset += column;
    }
    std::vector<Position> getCurrentPosition()
    {
        std::vector<Position> newPosition;
        for (Position it : rotationState[state])
        {
            it.row += rowOffset;
            it.column += columnOffset;
            newPosition.push_back(it);
        }
        return newPosition;
    }
    void rotate()
    {
        state++;
        if (state > 3)
            state = 0;
    }
    void rotateBack()
    {
        state--;
        if (state < 0)
            state = 3;
    }
};

class LBlock : public Block
{
public:
    LBlock()
    {
        colorId = 1;
        rotationState[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
        rotationState[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
        rotationState[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
        rotationState[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
        move(0, 3);
    }
};

class JBlock : public Block
{
public:
    JBlock()
    {
        colorId = 2;
        rotationState[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
        rotationState[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
        rotationState[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
        rotationState[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};
        move(0, 3);
    }
};

class IBlock : public Block
{
public:
    IBlock()
    {
        colorId = 3;
        rotationState[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
        rotationState[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
        rotationState[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
        rotationState[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
        move(-1, 3);
    }
};

class OBlock : public Block
{
public:
    OBlock()
    {
        colorId = 4;
        rotationState[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
        rotationState[1] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
        rotationState[2] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
        rotationState[3] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
        move(0, 4);
    }
};

class SBlock : public Block
{
public:
    SBlock()
    {
        colorId = 5;
        rotationState[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
        rotationState[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
        rotationState[2] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
        rotationState[3] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
        move(0, 3);
    }
};

class TBlock : public Block
{
public:
    TBlock()
    {
        colorId = 6;
        rotationState[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
        rotationState[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
        rotationState[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
        rotationState[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
        move(0, 3);
    }
};

class ZBlock : public Block
{
public:
    ZBlock()
    {
        colorId = 7;
        rotationState[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
        rotationState[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
        rotationState[2] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
        rotationState[3] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
        move(0, 4);
    }
};
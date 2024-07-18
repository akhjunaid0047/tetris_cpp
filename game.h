#pragma once
#include "grid.cpp"
#include "block.h"
#include <random>
class Game
{
    int gameOver;
    double lastMoveTime = 0;
    std::vector<Block> blocks;
    Block currentBlock, nextBlock;

public:
    Game()
    {
        gameOver = 0;
        grid = Grid();
        blocks = {LBlock(),
                  JBlock(),
                  IBlock(),
                  OBlock(),
                  SBlock(),
                  TBlock(),
                  ZBlock()};
        currentBlock = getBlock();
        nextBlock = getBlock();
    }
    Grid grid;
    void Reset()
    {
        grid.initialise();
        currentBlock = getBlock();
        nextBlock = getBlock();
    }
    int getRandomNumber(int min, int max)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }
    Block getBlock()
    {
        int randomNumber = getRandomNumber(0, 6);
        return blocks[randomNumber];
    }
    void draw()
    {
        grid.Draw();
        currentBlock.draw();
    }
    int isBlockOut()
    {
        std::vector<Position> currentPosition = currentBlock.getCurrentPosition();
        for (Position it : currentPosition)
        {
            if (grid.isCellOutside(it.row, it.column))
                return 1;
        }
        return 0;
    }
    void lockBlock()
    {
        for (Position it : currentBlock.getCurrentPosition())
            grid.grid[it.row][it.column] = currentBlock.colorId;
        currentBlock = nextBlock;
        if (!blockOverlaps())
        {
            gameOver = 1;
        }
        nextBlock = getBlock();
        grid.clearCompletedRows();
    }
    int blockOverlaps()
    {
        for (Position it : currentBlock.getCurrentPosition())
        {
            if (!grid.isCellEmpty(it.row, it.column))
                return 0;
        }
        return 1;
    }
    void moveDown()
    {
        if (gameOver)
            return;
        currentBlock.move(1, 0);
        if (isBlockOut() or !blockOverlaps())
        {
            currentBlock.move(-1, 0);
            lockBlock();
        }
    }
    void input()
    {
        if (gameOver and IsKeyPressed(KEY_R))
        {
            gameOver = 0;
            Reset();
        }
        double currentTime = GetTime();
        if (currentTime - lastMoveTime >= 0.1122)
        {
            if (IsKeyDown(KEY_LEFT))
            {
                if (!gameOver)
                {
                    currentBlock.move(0, -1);
                    if (isBlockOut() or !blockOverlaps())
                        currentBlock.move(0, 1);
                }
            }
            if (IsKeyDown(KEY_RIGHT))
            {
                if (!gameOver)
                {
                    currentBlock.move(0, 1);
                    if (isBlockOut() or !blockOverlaps())
                        currentBlock.move(0, -1);
                }
            }
            if (IsKeyDown(KEY_UP))
            {
                if (!gameOver)
                {
                    currentBlock.rotate();
                    if (isBlockOut() or !blockOverlaps())
                        currentBlock.rotateBack();
                }
            }
            if (IsKeyDown(KEY_DOWN))
            {
                if (!gameOver)
                    moveDown();
            }
            lastMoveTime = currentTime;
        }
    }
};
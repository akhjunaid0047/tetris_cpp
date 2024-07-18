#pragma once
#include "grid.cpp"
#include "block.h"
#include <random>
class Game
{
    double lastMoveTime = 0;
    std::vector<Block> blocks;
    Block currentBlock;

public:
    Game()
    {
        grid = Grid();
        blocks = {LBlock(),
                  JBlock(),
                  IBlock(),
                  OBlock(),
                  SBlock(),
                  TBlock(),
                  ZBlock()};
        currentBlock = getBlock();
    }
    Grid grid;
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
    void moveDown()
    {
        currentBlock.move(1, 0);
                if (isBlockOut())
                    currentBlock.move(-1, 0);
    }
    void input()
    {
        double currentTime = GetTime();
        if (currentTime - lastMoveTime >= 0.12)
        {
            if (IsKeyDown(KEY_LEFT))
            {
                currentBlock.move(0, -1);
                if (isBlockOut())
                    currentBlock.move(0, 1);
            }
            if (IsKeyDown(KEY_RIGHT))
            {
                currentBlock.move(0, 1);
                if (isBlockOut())
                    currentBlock.move(0, -1);
            }
            if (IsKeyDown(KEY_UP))
            {
                currentBlock.rotate();
                if (isBlockOut())
                    currentBlock.move(0, -1);
            }
            if (IsKeyDown(KEY_DOWN))
            {
                moveDown();
            }
            lastMoveTime = currentTime;
        }
    }
};
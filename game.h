#pragma once
#include "grid.cpp"
#include "block.h"
#include <random>
class Game
{
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
        int randomNumber = getRandomNumber(0, 7);
        return blocks[randomNumber];
    }
    void draw()
    {
        grid.Draw();
        currentBlock.draw();
    }
};
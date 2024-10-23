#pragma once
#include <vector>
#include <iostream>

struct Vector2
{
    Vector2(int newX = 0, int newY = 0) : x(newX), y(newY)
    {
    }

    int x;
    int y;
};

class Board
{
  public:
    Board(int size);

  private:
    std::vector<Vector2> boardContents;
};

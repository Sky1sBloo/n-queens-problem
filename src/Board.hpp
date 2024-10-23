#pragma once
#include <ostream>
#include <vector>

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

    friend std::ostream &operator<<(std::ostream &os, const Board &board);

  private:
    std::vector<Vector2> boardContents;
};

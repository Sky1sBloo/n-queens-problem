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

class QueenBuilder 
{
  public:
    QueenBuilder(int size);

    friend std::ostream &operator<<(std::ostream &os, const QueenBuilder &board);

  private:
    std::vector<Vector2> boardContents;
};

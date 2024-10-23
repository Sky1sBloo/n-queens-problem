#pragma once
#include <array>

struct Vector2
{
    Vector2(int newX = 0, int newY = 0) : x(newX), y(newY)
    {
    }

    int x;
    int y;
};

template <std::size_t N>
class Board
{
  public:
    Board();

  private:
    std::array<bool, N> boardContents;
};

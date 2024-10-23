#pragma once
#include <array>
#include <iostream>

struct Vector2
{
    Vector2(int newX = 0, int newY = 0) : x(newX), y(newY)
    {
    }

    int x;
    int y;
};

template <std::size_t N> class Board
{
  public:
    Board()
    {
        int xStartPos = (N % 2 == 0) ? 1 : 0;
        
        for (int i = xStartPos; i < N; i++)
        {
            int rowPos = i * 2;
            if (rowPos >= N)
            {
                rowPos = rowPos - N;
            }
            boardContents[i] = Vector2(rowPos, i);
        }

        for (const Vector2 &pos : boardContents)
        {
            std::cout << pos.x << " " << pos.y << std::endl;
        }
    }

  private:
    std::array<Vector2, N> boardContents;
    int nMax;
};

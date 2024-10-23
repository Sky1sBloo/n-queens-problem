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
        int evenOffset = (N % 2 == 0) ? 1 : 0;
        int xStartPos = evenOffset;
        
        for (int i = 0; i < N; i++)
        {
            if (xStartPos >= N)
            {
                xStartPos = xStartPos - N - (evenOffset);
            }
            boardContents[i] = Vector2(i, xStartPos);
            xStartPos += 2;
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

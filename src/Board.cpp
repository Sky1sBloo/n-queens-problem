#include "Board.hpp"

Board::Board(int size)
{
    boardContents.reserve(size);
    int evenOffset = (size % 2 == 0) ? 1 : 0;
    int xStartPos = evenOffset;

    for (int i = 0; i < size; i++)
    {
        if (xStartPos >= size)
        {
            xStartPos = xStartPos - size - (evenOffset);
        }
        boardContents[i] = Vector2(i, xStartPos);
        xStartPos += 2;
    }

    for (const Vector2 &pos : boardContents)
    {
        std::cout << pos.x << " " << pos.y << std::endl;
    }
}

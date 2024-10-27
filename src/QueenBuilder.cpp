#include "QueenBuilder.hpp"

QueenBuilder::QueenBuilder(int size)
{
    // TODO: Add limitation for values less than 3
    boardContents.reserve(size);
    int evenOffset = (size % 2 == 0) ? 1 : 0;
    int xStartPos = evenOffset;

    for (int i = 0; i < size; i++)
    {
        if (xStartPos >= size)
        {
            xStartPos = xStartPos - size - (evenOffset);
        }
        boardContents.emplace_back(i, xStartPos);
        xStartPos += 2;
    }
}

std::ostream &operator<<(std::ostream &os, const QueenBuilder &board)
{
    for (const Vector2& pos : board.boardContents)
    {
        os << pos.x << ", " << pos.y << '\n';
    }


    return os;
}

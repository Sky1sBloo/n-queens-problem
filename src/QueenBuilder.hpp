#pragma once
#include <ostream>

#include "IterativeStack.hpp"

struct Vector2 {
    Vector2(int newX = 0, int newY = 0)
        : x(newX)
        , y(newY)
    {
    }

    int x;
    int y;
};

template <int Size>
class QueenBuilder {
public:
    QueenBuilder();

    friend std::ostream& operator<<(std::ostream& os, const QueenBuilder& board);

private:
    IterativeStack<Vector2, Size> queenPositions;
};

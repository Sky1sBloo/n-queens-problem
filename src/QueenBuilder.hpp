#pragma once
#include <cstddef>
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

class QueenBuilder {
public:
    QueenBuilder(std::size_t size);
    bool topPositionIntersects();

    friend std::ostream& operator<<(std::ostream& os, QueenBuilder& board);

private:
    IterativeStack<Vector2> positions;
};

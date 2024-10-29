#pragma once
#include <cstddef>
#include <ostream>

#include "IterativeStack.hpp"

struct Position {
    Position(int newColumn, int newRow) :
        column(newColumn), row(newRow)
    {
    }

    int column;
    int row;
};

class QueenBuilder {
public:
    QueenBuilder(std::size_t size);
    bool topPositionIntersects();

    friend std::ostream& operator<<(std::ostream& os, QueenBuilder& board);

private:
    IterativeStack<Position> positions;
};

class QueenBuilderException : public std::exception {
public:
    const char* what()
    {
        return "Cannot find solutions";
    }
};

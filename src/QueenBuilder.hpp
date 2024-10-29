#pragma once
#include <cstddef>
#include <ostream>

#include "IterativeStack.hpp"

/**
 * Struct representing a queen position
 */
struct Position {
    Position(int newColumn, int newRow)
        : column(newColumn)
        , row(newRow)
    {
    }

    int column;
    int row;
};

/**
 * Class used to generate the n-queens-problem
 *
 * Throws QueenBuilderException if it cannot find a solution
 */
class QueenBuilder {
public:
    /**
     * Positions is generated in here
     */
    QueenBuilder(std::size_t size);

    /**
     * Used to retrieve position data
     * Can be stored using std::stringstream
     */
    friend std::ostream& operator<<(std::ostream& os, QueenBuilder& board);

private:
    IterativeStack<Position> positions;

    /**
     * Checks if the top of stack intersects with the previous ones
     *
     * @return True if the top is horizontally, vertically, or diagonally aligned
     */
    bool topPositionIntersects();
};

/**
 * Exception that gets thrown when QueenBuilder cannot generate solutions;
 */
class QueenBuilderException : public std::exception {
public:
    const char* what()
    {
        return "Cannot find solutions";
    }
};

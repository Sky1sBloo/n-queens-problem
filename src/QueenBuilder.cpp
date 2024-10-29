#include "QueenBuilder.hpp"
#include <algorithm>
#include <cstdlib>

QueenBuilder::QueenBuilder(std::size_t size)
    : positions(size)
{
    bool foundPositions = false;

    std::size_t currentCol = 0; // (positions.isEmpty()) ? 0 : (positions.top().column + 2) % size;
    while (!foundPositions) {
        if (topPositionIntersects()) {
            while (positions.getLength() > 1 && positions.top().column == size - 1) {
                positions.pop();
            }
            if (!positions.isEmpty()) {
                positions.top().column++;

                if (positions.top().column >= size && positions.getLength() == 1) {
                    throw QueenBuilderException();
                }
            }
        } else {
            if (positions.getLength() == size) {
                foundPositions = true;
                continue;
            }
            std::size_t currentRow = positions.getLength();
            Position newNode(currentCol, currentRow);
            positions.push(newNode);
        }
    }
}

bool QueenBuilder::topPositionIntersects()
{
    // Used this to loop until second to the last value
    auto intersectPosition = std::find_if(positions.begin(), std::prev(positions.end()), [&](const Position& iPos) {
        if (positions.top().column == iPos.column || positions.top().row == iPos.row) {
            return true;
        }
        if (std::abs(positions.top().column - iPos.column) == std::abs(positions.top().row - iPos.row)) {
            return true;
        }
        return false;
    });

    bool foundIntersection = intersectPosition != std::prev(positions.end());
    return foundIntersection;
}

std::ostream& operator<<(std::ostream& os, QueenBuilder& board)
{
    for (const Position& iPos : board.positions) {
        os << iPos.column << ", " << iPos.row << '\n';
    }

    return os;
}

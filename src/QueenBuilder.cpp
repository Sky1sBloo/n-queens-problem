#include "QueenBuilder.hpp"
#include <algorithm>
#include <cstdlib>

QueenBuilder::QueenBuilder(std::size_t size)
    : positions({}, size)
{
    bool foundPositions = false;

    std::size_t currentCol = 0; // (positions.isEmpty()) ? 0 : (positions.top().x + 2) % size;
    while (!foundPositions) {
        if (topPositionIntersects()) {
            while (positions.getLength() > 1 && positions.top().x == size - 1) {
                positions.pop();
            }
            if (!positions.isEmpty()) {
                positions.top().x++;

                if (positions.top().x >= size && positions.getLength() == 1) {
                    throw QueenBuilderException();
                }
            }
        } else {
            if (positions.getLength() == size) {
                foundPositions = true;
                continue;
            }
            std::size_t currentRow = positions.getLength();
            Vector2 newNode(currentCol, currentRow);
            positions.push(newNode);
        }
    }
}

bool QueenBuilder::topPositionIntersects()
{
    // Used this to loop until second to the last value
    auto intersectPosition = std::find_if(positions.begin(), std::prev(positions.end()), [&](const Vector2& iPos) {
        if (positions.top().x == iPos.x || positions.top().y == iPos.y) {
            return true;
        }
        if (std::abs(positions.top().x - iPos.x) == std::abs(positions.top().y - iPos.y)) {
            return true;
        }
        return false;
    });

    bool foundIntersection = intersectPosition != std::prev(positions.end());
    return foundIntersection;
}

std::ostream& operator<<(std::ostream& os, QueenBuilder& board)
{
    for (const Vector2& iPos : board.positions) {
        os << iPos.x << ", " << iPos.y << '\n';
    }

    return os;
}

#include "QueenBuilder.hpp"
#include <cstdlib>

QueenBuilder::QueenBuilder(std::size_t size)
    : positions({}, size)
{
    bool foundPositions = false;

    while (!foundPositions) {

        std::size_t currentCol = 0; // (positions.isEmpty()) ? 0 : (positions.top().x + 2) % size;
        if (topPositionIntersects()) {
            while (positions.getLength() > 1 || positions.top().x == size - 1) {
                positions.pop();
            }
            if (!positions.isEmpty()) {
                positions.top().x++;
                positions.top().x %= size;
            }
        } else {
            if (positions.getLength() == size) {
                foundPositions = true;
                continue;
            }
            std::size_t currentRow = positions.getLength();
            Vector2 newNode(currentCol, currentRow);
            positions.push(newNode);
            currentCol = (newNode.x + 2) % size;
        }
    }
}

bool QueenBuilder::topPositionIntersects()
{
    for (const Vector2& iPos : positions) {
        if (iPos.y == positions.top().y) {
            continue;
        }
        if (positions.top().x == iPos.x || positions.top().y == iPos.y) {
            return true;
        }
        if (std::abs(positions.top().x - iPos.x) == std::abs(positions.top().y - iPos.y)) {
            return true;
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const QueenBuilder& board)
{
    for (const Vector2& iPos : board.positions) {
        os << iPos.x << ", " << iPos.y << '\n';
    }

    return os;
}

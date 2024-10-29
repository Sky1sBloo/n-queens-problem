#include "QueenBuilder.hpp"
#include <algorithm>
#include <cstdlib>

QueenBuilder::QueenBuilder(std::size_t size)
    : positions({}, size)
{
    bool foundPositions = false;
    std::size_t currentCol = (positions.isEmpty()) ? 0 : (positions.top().x + 2) % size;

    while (!foundPositions) {

        if (topPositionIntersects()) {
            while (!positions.isEmpty() && positions.top().x != currentCol) {
                positions.pop();

                if (!positions.isEmpty()) {
                    positions.top().x++;
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
            currentCol = (newNode.x + 2) % size;
        }
    }
}

bool QueenBuilder::topPositionIntersects()
{
    bool isIntersecting = false;

    if (positions.getLength() <= 1) {
        return false;
    }

    std::for_each(positions.begin(), positions.end() - 1, [&](const Vector2& iPos) {
        if (positions.top().x == iPos.x || positions.top().y == iPos.y) {
            isIntersecting = true;
            return;
        }
        if (std::abs(positions.top().x - iPos.x) == std::abs(positions.top().y - iPos.y)) {
            isIntersecting = true;
            return;
        }
    });
    return isIntersecting;
}

std::ostream& operator<<(std::ostream& os, const QueenBuilder& board)
{
    for (const Vector2& iPos : board.positions) {
        os << iPos.x << ", " << iPos.y << '\n';
    }

    return os;
}

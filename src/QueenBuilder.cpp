#include "QueenBuilder.hpp"
#include <cstdlib>

QueenBuilder::QueenBuilder(std::size_t size)
    : positions({}, size)
{
    int newNodeStartCol = (positions.isEmpty()) ? 0 : (positions.top().x + 2) % size; // Starting column of new node
    int newNodeCol = newNodeStartCol;  // This will be incremented when it intersects
    bool foundSet = false;

    while (!foundSet) {
        Vector2 newNodePos(newNodeCol, positions.getLength());

        if (positionIntersects(newNodePos)) {
            if (++newNodePos.x == newNodeStartCol) {
                newNodeStartCol = positions.top().x + 1;
                newNodeStartCol %= size;
                newNodeCol = newNodeStartCol;
                positions.pop();
                continue;
            }
            newNodeCol++;
            newNodeCol %= size;
        } else {
            positions.push(newNodePos);
            newNodeStartCol = (newNodePos.x + 2) % size;
            newNodeCol = newNodeStartCol;

            if (positions.getLength() == size) {
                foundSet = true;
            }
        }
    }
}

bool QueenBuilder::positionIntersects(const Vector2& newPosition)
{
    for (const Vector2& iPos : positions) {
        if (newPosition.x == iPos.x || newPosition.y == iPos.y) {
            return true;
        }
        if (std::abs(newPosition.y - iPos.y) == std::abs(newPosition.x - iPos.x)) {
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

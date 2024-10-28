#include "QueenBuilder.hpp"
#include <cstdlib>

QueenBuilder::QueenBuilder(std::size_t size)
    : positions({}, size)
{
    int newNodeStartCol = (positions.isEmpty()) ? 0 : (positions.top().x + 2) % size; // Starting column of new node
    bool foundSet = false;

    while (!foundSet) {
        Vector2 newNodePos(newNodeStartCol, positions.getLength());

        if (positionIntersects(newNodePos)) {
            if (++newNodePos.x == newNodeStartCol) {
                positions.pop();
                if (positions.getLength() == 0) {
                    break;
                }
                positions.pop();
                newNodeStartCol++;
                continue;
            }
            positions.pop();
            newNodeStartCol++;

        } else {
            positions.push(newNodePos);
            newNodeStartCol = (newNodePos.x + 2) % size;

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

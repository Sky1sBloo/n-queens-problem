#include "QueenBuilder.hpp"

QueenBuilder::QueenBuilder(std::size_t size)
    : positions({}, size)
{
    int newNodeStartCol = (positions.isEmpty()) ? 0 : (positions.top().x + 2) % size;  // Starting column of new node
    bool foundSet = false;

    while (foundSet) {
        Vector2 newNodePos(newNodeStartCol, positions.getLength());

        if (positionIntersects(newNodePos)) {
            if (++newNodePos.x == newNodeStartCol) {
                positions.pop();
                newNodeStartCol++;
            }

            positions.pop();
        } else {
            if (positions.getLength() == size) {
                foundSet = true;
            }
            positions.push(newNodePos);
            newNodeStartCol = (newNodePos.x + 2) % size;
        }
    }
}

bool QueenBuilder::positionIntersects(const Vector2& newPosition)
{
    for (const Vector2& iPos : positions) {
        if (newPosition.x == iPos.x || newPosition.y == iPos.y) {
            return false;
        }
        if (newPosition.y - iPos.y == newPosition.x - iPos.x) {
            return false;
        }
    }
    return true;
}

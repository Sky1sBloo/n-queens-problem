#include "QueenBuilder.hpp"

QueenBuilder::QueenBuilder(std::size_t size)
    : positions({}, size)
{
    int currentRow = 0;
    int newNodeStartCol = (positions.isEmpty()) ? 0 : (positions.top().x + 2) % size;  // Starting column of new node

    while (true) {
        Vector2 newNodePos(newNodeStartCol, currentRow);

        if (positionIntersects(newNodePos)) {
            if (++newNodePos.x == newNodeStartCol) {
                positions.pop();
                currentRow--;
                newNodeStartCol++;
            }

            positions.pop();
        } else {
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

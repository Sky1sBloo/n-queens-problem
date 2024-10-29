#include "QueenBuilder.hpp"
#include <algorithm>
#include <cstdlib>

QueenBuilder::QueenBuilder(std::size_t size)
    : positions({}, size)
{

}

bool QueenBuilder::topPositionIntersects()
{
    std::for_each(positions.begin(), positions.end() - 1, [&](const Vector2& iPos) {

    });;
    return false;
}

std::ostream& operator<<(std::ostream& os, const QueenBuilder& board)
{
    for (const Vector2& iPos : board.positions) {
        os << iPos.x << ", " << iPos.y << '\n';
    }

    return os;
}

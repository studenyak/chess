#include "move.h"

namespace chess
{

    Move::Move(Pos fromPos, Pos toPos)
        : m_FromPos(fromPos)
        , m_ToPos(toPos)
    {
    }

    Pos &Move::toPos()
    {
        return m_ToPos;
    }

    Pos &Move::fromPos()
    {
        return m_FromPos;
    }
}

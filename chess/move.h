#ifndef MOVE_H
#define MOVE_H
#include "pos.h"

namespace chess
{
    class Move
    {
    public:
        Move();
        Move(Pos fromPos, Pos toPos);
        Pos& fromPos();
        Pos &toPos();

    private:
        Pos m_FromPos;
        Pos m_ToPos;
    };
}
#endif // MOVE_H

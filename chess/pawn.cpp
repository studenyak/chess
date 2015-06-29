#include "pawn.h"

namespace chess
{
    Pawn::Pawn(const std::string &strName)
        : Piece(strName)
    {}

    bool Pawn::isMovingPossible(const std::string &strFromAddr,
                                const std::string &strToAddr,
                                std::vector<std::string>& path) const
    {
        Pos fromPos(strFromAddr);
        Pos toPos(strToAddr);
        int diffY = abs(toPos.getY() - fromPos.getY());
        int diffX = abs(toPos.getX() - fromPos.getX());
        if(diffX)
            return false;

        if(diffY > 1)
            return false;

        path.push_back(strToAddr);
        return true;
    }
}

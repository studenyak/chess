#include "pawn.h"

namespace chess
{
    Pawn::Pawn(const std::string &strName)
        : Piece(strName)
    {}

    bool Pawn::isMovingPossible(const std::string &strFromAddr,
                                const std::string &strToAddr,
                                std::vector<std::string>& path,
                                bool bFlag) const
    {
        Pos fromPos(strFromAddr);
        Pos toPos(strToAddr);
        int diffY = 0;

        // Exclude back direction moves
        if(m_bWhite)
            diffY = toPos.getY() - fromPos.getY();
        else
            diffY = fromPos.getY() - toPos.getY();
        if(diffY < 0)
            return false;

        int diffX = abs(toPos.getX() - fromPos.getX());

        if(diffY == 1 && diffX == 1 && bFlag)
            return true;

        // Exclude moves more that 1 vertical cell
        if((m_bWhite && (strFromAddr.find("2") != std::string::npos)) ||
                (!m_bWhite && (strFromAddr.find("7") != std::string::npos)))
        {
            if(diffY > 2)
                return false;
        }
        else
        {
            if(diffY > 1)
                return false;
        }


        // Exclude horisontal direction moves
        if(diffX)
            return false;


        path.push_back(strToAddr);
        return true;
    }
}

#include "king.h"

namespace chess {

    King::King(const std::string &strName)
        : Piece(strName)
    {}

    bool King::isMovingPossible(const std::string &strFromAddr,
                                const std::string &strToAddr,
                                std::vector<std::string>& path,
                                bool bFlag) const
    {
        Pos fromPos(strFromAddr);
        Pos toPos(strToAddr);;

        if(abs(toPos.getX() - fromPos.getX()) > 1)
            return false;
        if(abs(toPos.getY() - fromPos.getY()) > 1)
            return false;

        path.push_back(strToAddr);
        return true;
    }
}

#include "knight.h"

namespace chess {

    Knight::Knight(const std::string &strName) : Piece(strName){}
    bool Knight::isMovingPossible(const std::string &strFromAddr,
                                 const std::string &strToAddr,
                                  std::vector<std::string>& path) const
    {
        Pos fromPos(strFromAddr);
        Pos toPos(strToAddr);

        if(abs(toPos.getX() - fromPos.getX()) == 2 && abs(toPos.getY() - fromPos.getY()) == 1 )
            return true;
        if(abs(toPos.getY() - fromPos.getY()) == 2 && abs(toPos.getX() - fromPos.getX()) == 1 )
            return true;

        path.push_back(strToAddr);
        return false;
    }
}

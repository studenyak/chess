#include "rook.h"

namespace chess {

    Rook::Rook(const std::string &strName) : Piece(strName){}
    bool Rook::isMovingPossible(const std::string &strFromAddr,
                                const std::string &strToAddr,
                                std::vector<std::string>& path, bool bFlag) const
    {
        Pos fromPos(strFromAddr);
        Pos toPos(strToAddr);

        if( toPos.getX() == fromPos.getX() )
        {
            for(int y = fromPos.getY() + 1; y < toPos.getY(); y++)
                path.push_back(Pos(toPos.getX(), y));
            for(int y = fromPos.getY() - 1; y > toPos.getY(); y--)
                path.push_back(Pos(toPos.getX(), y));
            return true;
        }

        if( toPos.getY() == fromPos.getY())
        {
            for(int x = fromPos.getX() + 1; x < toPos.getX(); x++)
                path.push_back(Pos(x, toPos.getY()));
            for(int x = fromPos.getX() - 1; x > toPos.getX(); x--)
                path.push_back(Pos(x, toPos.getY()));
            return true;
        }

        return false;
    }
}

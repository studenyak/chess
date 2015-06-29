#include "bishop.h"

namespace chess
{
    Bishop::Bishop(const std::string &strName) : Piece(strName){}
    bool Bishop::isMovingPossible(const std::string &strFromAddr,
                                 const std::string &strToAddr,
                                  std::vector<std::string> &path,
                                  bool bFlag) const
    {
        Pos fromPos(strFromAddr);
        Pos toPos(strToAddr);

        int diff = abs(toPos.getX() - fromPos.getX());

        if(abs(toPos.getX() - fromPos.getX()) == abs(toPos.getY() - fromPos.getY()))
        {
            if(toPos.getY() > fromPos.getY() && toPos.getX() > fromPos.getX())
                for(int i = 1; i < diff; i++)
                    path.push_back(Pos(fromPos.getX() + i, fromPos.getY() + i));
            else if(toPos.getY() < fromPos.getY() && toPos.getX() < fromPos.getX())
                for(int i = 1; i > diff; i++)
                    path.push_back(Pos(fromPos.getX() - i, fromPos.getY() - i));
            else if(toPos.getY() > fromPos.getY() && toPos.getX() < fromPos.getX())
                for(int i = 1; i > diff; i++)
                    path.push_back(Pos(fromPos.getX() - i, fromPos.getY() + i));
            else
                for(int i = 1; i > diff; i++)
                    path.push_back(Pos(fromPos.getX() + i, fromPos.getY() - i));

            return true;
        }
        return false;
    }

}

#include "queen.h"

namespace chess {

    Queen::Queen(const std::string &strName) : Piece(strName){}
    bool Queen::isMovingPossible(const std::string &strFromAddr,
                                 const std::string &strToAddr,
                                 std::vector<std::string>& path) const
    {
        return Bishop::isMovingPossible(strFromAddr, strToAddr, path) ||
                Rook::isMovingPossible(strFromAddr, strToAddr, path);
    }
}

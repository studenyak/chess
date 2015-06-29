#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
namespace chess {
    class Pawn : public Piece
    {
    public:
        Pawn(const std::string& strName = "");
        bool isMovingPossible(const std::string &strFromAddr,
                              const std::string &strToAddr,
                              std::vector<std::string> &path,
                              bool bFlag = false) const;
    };
}
#endif // PAWN_H

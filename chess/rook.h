#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
namespace chess {
    class Rook : public virtual Piece
    {
    public:
        Rook(const std::string& strName = "");
        bool isMovingPossible(const std::string &strFromAddr,
                              const std::string &strToAddr,
                              std::vector<std::string>& path,
                              bool bFlag = false) const;
    };
}

#endif // ROOK_H

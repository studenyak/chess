#ifndef KING_H
#define KING_H

#include "piece.h"

namespace chess {
    class King : public Piece
    {
    public:
        King(const std::string& strName = "");
        bool isMovingPossible(const std::string &strFromAddr,
                              const std::string &strToAddr,
                              std::vector<std::string>& path,
                              bool bFlag = false) const;
    };
}

#endif // KING_H

#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

namespace chess {
    class Knight : public Piece
    {
    public:
        Knight(const std::string& strName = "");
        bool isMovingPossible(const std::string &strFromAddr,
                              const std::string &strToAddr,
                              std::vector<std::string>& path) const;
    };
}
#endif // KNIGHT_H

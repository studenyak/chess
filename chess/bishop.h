#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
namespace chess {
    class Bishop : public virtual Piece
    {
    public:
        Bishop(const std::string& strName = "");
        bool isMovingPossible(const std::string &strFromAddr,
                              const std::string &strToAddr,
                              std::vector<std::string>& path,
                              bool bFlag = false) const;
    };
}
#endif // BISHOP_H

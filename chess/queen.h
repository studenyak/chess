#ifndef QUEEN_H
#define QUEEN_H

#include "rook.h"
#include "bishop.h"
namespace chess {
    class Queen : public Rook, public Bishop
    {
    public:
        Queen(const std::string& strName = "");
        bool isMovingPossible(const std::string &strFromAddr,
                              const std::string &strToAddr,
                              std::vector<std::string>& path,
                              bool bFlag = false) const;
    };
}

#endif // QUEEN_H

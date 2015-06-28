#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include <map>

namespace chess
{
    class Board
    {
    public:
        Board();
        void setPiecePosition(const std::string& strAddr,
                              const Piece* pPiece);

        bool movePiece(const std::string& strFromAddr,
                       const std::string& strToAddr);

        bool movePiece(unsigned int fromIndex,
                       unsigned int toIndex);

        const char *getPieceName(unsigned int nIndex);
        unsigned int count() const;

#ifndef __GOOGLE_TEST__
    private:
#endif
        std::map<std::string, const Piece*> m_PiecePool;
        const char *indexToAddr(unsigned int nIndex, std::string &strAddr);
    };
}
#endif // BOARD_H

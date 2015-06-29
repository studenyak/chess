#ifndef PIECE_H
#define PIECE_H

#include "pos.h"
#include <vector>

namespace chess {

    class Piece
    {
    public:
        Piece(const std::string& strName = "");
        virtual ~Piece();
        virtual bool isMovingPossible(const std::string& strFromAddr,
                                      const std::string& strToAddr,
                                      std::vector<std::string>& path,
                                      bool bFlag = false) const = 0;
        const char* getName() const;
        bool isWhite() const;

    protected:
        bool m_bWhite;
        std::string m_strName;
    };

    Piece* createPiece(const std::string& strPieceType);

}
#endif // PIECE_H

#include "piece.h"
#include <stdlib.h>


namespace chess {

    Piece::Piece(const std::string &strName)
        : m_bWhite(true)
        , m_strName(strName)
    {
        if(strName.find("white") == std::string::npos)
            m_bWhite = false;
    }

    Pos strAddrToPos(const std::string& strAddr)
    {
        Pos pos = {0,0};
        const char* chPos = strAddr.c_str();
        pos.x = chPos[0] - 0x61;
        if(pos.x >= 8 || pos.x < 0)
            pos.x = -1;
        pos.y = chPos[1] - 0x31;
        if(pos.y >= 8 || pos.y < 0)
            pos.y = -1;

        return pos;
    }

    const char *Piece::getName() const
    {
        return m_strName.c_str();
    }

    Piece::~Piece()
    {}

    Pawn::Pawn(const std::string &strName)
        : Piece(strName)
    {}

    bool Pawn::isMovingPossible(const std::string &strFromAddr,
                                 const std::string &strToAddr) const
    {
        Pos fromPos = strAddrToPos(strFromAddr);
        Pos toPos = strAddrToPos(strToAddr);
        if(fromPos.x != toPos.x)
            return false;

        if(abs(toPos.y - fromPos.y) > 1)
            return false;

        return true;
    }

    Piece *createPiece(const std::string &strPieceType)
    {
        if(strPieceType.find("pawn") != std::string::npos)
            return new Pawn(strPieceType);
        return 0;
    }

}

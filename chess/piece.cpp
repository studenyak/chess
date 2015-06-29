#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include <stdlib.h>

namespace chess {

    Piece::Piece(const std::string &strName)
        : m_bWhite(true)
        , m_strName(strName)
    {
        if(strName.find("white") == std::string::npos)
            m_bWhite = false;
    }

    bool Piece::isWhite() const
    {
        return m_bWhite;
    }

    const char *Piece::getName() const
    {
        return m_strName.c_str();
    }

    Piece::~Piece()
    {}

    Piece *createPiece(const std::string &strPieceType)
    {
        if(strPieceType.find("pawn") != std::string::npos)
            return new Pawn(strPieceType);

        if(strPieceType.find("rook") != std::string::npos)
            return new Rook(strPieceType);

        if(strPieceType.find("knight") != std::string::npos)
            return new Knight(strPieceType);

        if(strPieceType.find("bishop") != std::string::npos)
            return new Bishop(strPieceType);

        if(strPieceType.find("queen") != std::string::npos)
            return new Queen(strPieceType);

        if(strPieceType.find("king") != std::string::npos)
            return new King(strPieceType);

        return 0;
    }
}

#include "piece.h"
#include <stdlib.h>


namespace chess {

    Pos::Pos():m_nX(0), m_nY(0){}
    Pos::Pos(int x, int y):m_nX(x), m_nY(y)
    {

    }
    Pos::Pos(const std::string &strAddr)
        : m_nX(0)
        , m_nY(0)
    {
        m_strAddr = strAddr;
        const char* chPos = m_strAddr.c_str();
        m_nX = chPos[0] - 0x61;
        if(m_nX >= 8 || m_nX < 0)
            m_nX = -1;
        m_nY = chPos[1] - 0x31;
        if(m_nY >= 8 || m_nY < 0)
            m_nY = -1;
    }

    chess::Pos::operator std::string()
    {
        char chPos[3] = {0};
        if(m_nX >= 8 || m_nX < 0 || m_nY >= 8 || m_nY < 0)
            return "";

        chPos[0] = m_nX + 0x61;
        chPos[1] = m_nY + 0x31;
        m_strAddr.assign(chPos);
        return m_strAddr;
    }

    int Pos::getX()
    {
        return m_nX;
    }
    int Pos::getY()
    {
        return m_nY;
    }

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

    Pawn::Pawn(const std::string &strName)
        : Piece(strName)
    {}

    bool Pawn::isMovingPossible(const std::string &strFromAddr,
                                const std::string &strToAddr,
                                std::vector<std::string>& path) const
    {
        Pos fromPos(strFromAddr);
        Pos toPos(strToAddr);
        int diffY = abs(toPos.getY() - fromPos.getY());
        int diffX = abs(toPos.getX() - fromPos.getX());
        if(diffX)
            return false;

        if(diffY > 1)
            return false;

        path.push_back(strToAddr);
        return true;
    }

    Rook::Rook(const std::string &strName) : Piece(strName){}
    bool Rook::isMovingPossible(const std::string &strFromAddr,
                                 const std::string &strToAddr,
                                std::vector<std::string>& path) const
    {
        Pos fromPos(strFromAddr);
        Pos toPos(strToAddr);

        if( toPos.getX() == fromPos.getX() )
        {
            for(int y = fromPos.getY() + 1; y < toPos.getY(); y++)
                path.push_back(Pos(toPos.getX(), y));
            for(int y = fromPos.getY() - 1; y > toPos.getY(); y--)
                path.push_back(Pos(toPos.getX(), y));
            return true;
        }

        if( toPos.getY() == fromPos.getY())
        {
            for(int x = fromPos.getX() + 1; x < toPos.getX(); x++)
                path.push_back(Pos(x, toPos.getY()));
            for(int x = fromPos.getX() - 1; x > toPos.getX(); x--)
                path.push_back(Pos(x, toPos.getY()));
            return true;
        }

        return false;
    }

    Knight::Knight(const std::string &strName) : Piece(strName){}
    bool Knight::isMovingPossible(const std::string &strFromAddr,
                                 const std::string &strToAddr,
                                  std::vector<std::string>& path) const
    {
        Pos fromPos(strFromAddr);
        Pos toPos(strToAddr);

        if(abs(toPos.getX() - fromPos.getX()) == 2 && abs(toPos.getY() - fromPos.getY()) == 1 )
            return true;
        if(abs(toPos.getY() - fromPos.getY()) == 2 && abs(toPos.getX() - fromPos.getX()) == 1 )
            return true;

        path.push_back(strToAddr);
        return false;
    }

    Bishop::Bishop(const std::string &strName) : Piece(strName){}
    bool Bishop::isMovingPossible(const std::string &strFromAddr,
                                 const std::string &strToAddr,
                                  std::vector<std::string> &path) const
    {
        Pos fromPos(strFromAddr);
        Pos toPos(strToAddr);

        int diff = abs(toPos.getX() - fromPos.getX());

        if(abs(toPos.getX() - fromPos.getX()) == abs(toPos.getY() - fromPos.getY()))
        {
            if(toPos.getY() > fromPos.getY() && toPos.getX() > fromPos.getX())
                for(int i = 1; i < diff; i++)
                    path.push_back(Pos(fromPos.getX() + i, fromPos.getY() + i));
            else if(toPos.getY() < fromPos.getY() && toPos.getX() < fromPos.getX())
                for(int i = 1; i > diff; i++)
                    path.push_back(Pos(fromPos.getX() - i, fromPos.getY() - i));
            else if(toPos.getY() > fromPos.getY() && toPos.getX() < fromPos.getX())
                for(int i = 1; i > diff; i++)
                    path.push_back(Pos(fromPos.getX() - i, fromPos.getY() + i));
            else
                for(int i = 1; i > diff; i++)
                    path.push_back(Pos(fromPos.getX() + i, fromPos.getY() - i));

            return true;
        }
        return false;
    }

    Queen::Queen(const std::string &strName) : Piece(strName){}
    bool Queen::isMovingPossible(const std::string &strFromAddr,
                                 const std::string &strToAddr,
                                 std::vector<std::string>& path) const
    {
        return Bishop::isMovingPossible(strFromAddr, strToAddr, path) ||
                Rook::isMovingPossible(strFromAddr, strToAddr, path);
    }

    King::King(const std::string &strName)
        : Piece(strName)
    {}

    bool King::isMovingPossible(const std::string &strFromAddr,
                                 const std::string &strToAddr,
                                std::vector<std::string>& path) const
    {
        Pos fromPos(strFromAddr);
        Pos toPos(strToAddr);;

        if(abs(toPos.getX() - fromPos.getX()) > 1)
            return false;
        if(abs(toPos.getY() - fromPos.getY()) > 1)
            return false;

        path.push_back(strToAddr);
        return true;
    }

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

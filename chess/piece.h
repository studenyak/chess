#ifndef PIECE_H
#define PIECE_H

#include <string>

namespace chess {

    struct Pos
    {
        int x;
        int y;
    };

    Pos strAddrToPos(const std::string& strAddr);

    class Piece
    {
    public:
        Piece(const std::string& strName = "");
        virtual ~Piece();
        virtual bool isMovingPossible(const std::string& strFromAddr,
                                      const std::string& strToAddr) const = 0;
        const char* getName() const;

    protected:
        bool m_bWhite;
        std::string m_strName;
    };

    class Pawn : public Piece
    {
    public:
        Pawn(const std::string& strName = "");
        bool isMovingPossible(const std::string &strFromAddr,
                              const std::string &strToAddr) const;
    };

    class Rook : Piece
    {
    public:
        Rook(const std::string& strName = "");
        bool isMovingPossible(const std::string &strFromAddr,
                              const std::string &strToAddr) const;
    };

    class Knight : Piece
    {
    public:
        Knight(const std::string& strName = "");
        bool isMovingPossible(const std::string &strFromAddr,
                              const std::string &strToAddr) const;
    };

    class Bishop : Piece
    {
    public:
        Bishop(const std::string& strName = "");
        bool isMovingPossible(const std::string &strFromAddr,
                              const std::string &strToAddr) const;
    };

    class Queen : Piece
    {
    public:
        Queen(const std::string& strName = "");
        bool isMovingPossible(const std::string &strFromAddr,
                              const std::string &strToAddr) const;
    };

    class King : Piece
    {
    public:
        King(const std::string& strName = "");
        bool isMovingPossible(const std::string &strFromAddr,
                              const std::string &strToAddr) const;
    };

    Piece* createPiece(const std::string& strPieceType);

}
#endif // PIECE_H

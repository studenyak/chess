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
                                      std::vector<std::string>& path) const = 0;
        const char* getName() const;
        bool isWhite() const;

    protected:
        bool m_bWhite;
        std::string m_strName;
    };

    class Pawn : public Piece
    {
    public:
        Pawn(const std::string& strName = "");
        bool isMovingPossible(const std::string &strFromAddr,
                              const std::string &strToAddr,
                              std::vector<std::string> &path) const;
    };

    class Rook : public virtual Piece
    {
    public:
        Rook(const std::string& strName = "");
        bool isMovingPossible(const std::string &strFromAddr,
                              const std::string &strToAddr,
                              std::vector<std::string>& path) const;
    };

    class Knight : public Piece
    {
    public:
        Knight(const std::string& strName = "");
        bool isMovingPossible(const std::string &strFromAddr,
                              const std::string &strToAddr,
                              std::vector<std::string>& path) const;
    };

    class Bishop : public virtual Piece
    {
    public:
        Bishop(const std::string& strName = "");
        bool isMovingPossible(const std::string &strFromAddr,
                              const std::string &strToAddr,
                              std::vector<std::string>& path) const;
    };

    class Queen : public Rook, public Bishop
    {
    public:
        Queen(const std::string& strName = "");
        bool isMovingPossible(const std::string &strFromAddr,
                              const std::string &strToAddr,
                              std::vector<std::string>& path) const;
    };

    class King : public Piece
    {
    public:
        King(const std::string& strName = "");
        bool isMovingPossible(const std::string &strFromAddr,
                              const std::string &strToAddr,
                              std::vector<std::string>& path) const;
    };

    Piece* createPiece(const std::string& strPieceType);

}
#endif // PIECE_H

#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>

namespace chess {

    class Pos
    {
    public:
        Pos();
        Pos(int x, int y);
        Pos(const std::string& strAddr);
        Pos(const char* chAddr);
        std::string toStringAddr();
        std::string &operator()();
        int getX();
        int getY();
    private:
        int m_nX;
        int m_nY;
        std::string m_strAddr;
    };

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

    class Rook : public Piece
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

    class Bishop : public Piece
    {
    public:
        Bishop(const std::string& strName = "");
        bool isMovingPossible(const std::string &strFromAddr,
                              const std::string &strToAddr,
                              std::vector<std::string>& path) const;
    };

    class Queen : public Piece
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

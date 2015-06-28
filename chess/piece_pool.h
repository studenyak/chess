#ifndef PIECE_POOL_H
#define PIECE_POOL_H

#include "piece.h"
#include <map>

namespace chess
{
    class PiecePool
    {
    public:
        static PiecePool& getInstance();
        ~PiecePool();
        unsigned int size();

    protected:
        PiecePool();
        PiecePool(const PiecePool&);
        void operator=(const PiecePool&);

    private:
        std::map<std::string, Piece> m_Pool;
    };
}
#endif // PIECE_POOL_H

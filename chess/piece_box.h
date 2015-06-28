#ifndef PIECE_BOX_H
#define PIECE_BOX_H

#include "piece.h"
#include <map>

namespace chess
{
    typedef std::map<std::string, Piece*> PIECE_POOL;
    class PieceBox
    {
    public:
        PieceBox();
        ~PieceBox();
        unsigned int create();
        unsigned int count() const;
        const PIECE_POOL& getPool() const;

    private:
        PIECE_POOL m_Pool;
    };
}

#endif // PIECE_BOX_H

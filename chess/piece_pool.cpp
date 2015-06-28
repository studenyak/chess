#include "piece_pool.h"

namespace chess
{
    PiecePool &PiecePool::getInstance()
    {
        static PiecePool s;
        return s;
    }

    PiecePool::~PiecePool()
    {
    }

    PiecePool::PiecePool()
    {
        // Create white pawn
        for(char ch = 'a'; ch <= 'h'; ch++)
        {
            std::string strAddr(&ch);
            strAddr.append("2");
            m_Pool[strAddr] = Piece(white);
        }

        //Create black pawn
        for(char ch = 'a'; ch <= 'h'; ch++)
        {
            std::string strAddr(&ch);
            strAddr.append("7");
            m_Pool[strAddr] = Piece(black);
        }
    }

    unsigned int PiecePool::size()
    {
        return m_Pool.size();
    }
}

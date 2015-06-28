#include "piece_box.h"


namespace chess
{
    PieceBox::PieceBox()
    {
    }

    PieceBox::~PieceBox()
    {
        for(PIECE_POOL::iterator it = m_Pool.begin();
            it != m_Pool.end();
            it++)
        {
            if(it->second)
                delete it->second;
        }
    }

    unsigned int PieceBox::create()
    {
        // Create white pawn
        char chAddr[3] = {0};
        for(char ch = 'a'; ch <= 'h'; ch++)
        {
            chAddr[0] = ch;
            chAddr[1] = '2';
            m_Pool[std::string(chAddr)] = createPiece("pawn_white");
        }

        //Create black pawn
        for(char ch = 'a'; ch <= 'h'; ch++)
        {
            chAddr[0] = ch;
            chAddr[1] = '7';
            m_Pool[std::string(chAddr)] = createPiece("pawn_black");
        }
        return m_Pool.size();
    }

    const PIECE_POOL &PieceBox::getPool() const
    {
        return m_Pool;
    }

    unsigned int PieceBox::count() const
    {
        return m_Pool.size();
    }
}

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

        m_Pool["a1"] = createPiece("rook_white");
        m_Pool["b1"] = createPiece("knight_white");
        m_Pool["c1"] = createPiece("bishop_white");
        m_Pool["d1"] = createPiece("queen_white");
        m_Pool["e1"] = createPiece("king_white");
        m_Pool["f1"] = createPiece("bishop_white");
        m_Pool["g1"] = createPiece("knight_white");
        m_Pool["h1"] = createPiece("rook_white");


        m_Pool["a8"] = createPiece("rook_black");
        m_Pool["b8"] = createPiece("knight_black");
        m_Pool["c8"] = createPiece("bishop_black");
        m_Pool["d8"] = createPiece("queen_black");
        m_Pool["e8"] = createPiece("king_black");
        m_Pool["f8"] = createPiece("bishop_black");
        m_Pool["g8"] = createPiece("knight_black");
        m_Pool["h8"] = createPiece("rook_black");

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

#include "board_filler.h"
#include "piece_box.h"

namespace chess
{
    BoardFiller::BoardFiller(Board& board, const PieceBox& pieceBox)
    {
        const PIECE_POOL& box = pieceBox.getPool();
        for(PIECE_POOL::const_iterator it = box.begin();
            it != box.end();
            it++)
        {
            board.setPiecePosition(it->first, it->second);
        }
    }
}

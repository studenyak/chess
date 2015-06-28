#ifndef BOARD_FILLER_H
#define BOARD_FILLER_H

#include "board.h"
#include "piece_box.h"

namespace chess
{
    class BoardFiller
    {
    public:
        BoardFiller(Board& board, const PieceBox& pieceBox);
    };
}

#endif // BOARD_FILLER_H

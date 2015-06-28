#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "piece_box.h"

namespace chess
{
    class Game
    {
    public:
        Game();
        int start();
        int load();
        Board &getBoard();

    private:
        Board m_Board;
        PieceBox m_PieceBox;
    };
}
#endif // GAME_H

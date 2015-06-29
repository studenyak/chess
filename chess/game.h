#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "piece_box.h"
#include <queue>

namespace chess
{
    class Game
    {
    public:
        Game();
        int start();
        void stop();
        Board &getBoard();
        bool movePiece(const std::string &strFromAddr,
                       const std::string &strToAddr,
                       bool bWhitePlayer);

    private:
        Board m_Board;
        PieceBox m_PieceBox;
        bool m_bWhitePlayer;
    };
}
#endif // GAME_H

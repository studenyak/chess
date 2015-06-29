#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "piece_box.h"
#include <queue>
#include "move.h"

namespace chess
{
    class Game
    {
    public:
        Game();
        int start();
        int stop();
        Board &getBoard();
        bool movePiece(const std::string &strFromAddr,
                       const std::string &strToAddr,
                       bool bWhitePlayer);

    private:
        Board m_Board;
        PieceBox m_PieceBox;
        bool m_bWhitePlayer;
        std::queue<Move> m_SavedMoves;

    };
}
#endif // GAME_H

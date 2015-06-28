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
        bool movePiece(const std::string &strFromAddr,
                       const std::string &strToAddr);

    private:
        Board m_Board;
        PieceBox m_PieceBox;
        bool m_bWhitePlayer;
    };
}
#endif // GAME_H

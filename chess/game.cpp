#include "game.h"
#include "board_filler.h"

namespace chess
{
    Game::Game()
    {
    }

    int Game::start()
    {
        try
        {
            m_PieceBox.create();
            BoardFiller(m_Board, m_PieceBox);
            return 0;
        }
        catch(...)
        {

        }
        return -1;
    }

    int Game::load()
    {
        return 0;
    }

    Board &Game::getBoard()
    {
        return m_Board;
    }
}

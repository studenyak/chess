#include "game.h"
#include "board_filler.h"

namespace chess
{
    Game::Game()
        : m_bWhitePlayer(true)
    {
    }

    int Game::start()
    {
        try
        {
            m_bWhitePlayer = true;
            m_PieceBox.create();
            BoardFiller(m_Board, m_PieceBox);
            return 0;
        }
        catch(...)
        {

        }
        return -1;
    }

    void Game::stop()
    {
        m_Board.release();
        m_PieceBox.release();
    }

    Board &Game::getBoard()
    {
        return m_Board;
    }

    bool Game::movePiece(const std::string &strFromAddr,
                         const std::string &strToAddr,
                         bool bWhitePlayer)
    {
        return m_Board.movePiece(strFromAddr, strToAddr, bWhitePlayer);
    }
}

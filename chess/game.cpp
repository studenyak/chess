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

    bool Game::movePiece(const std::string &strFromAddr,
                         const std::string &strToAddr)
    {
        if(m_Board.movePiece(strFromAddr, strToAddr, m_bWhitePlayer))
        {
            m_bWhitePlayer ^= true;
            return true;
        }
        return false;
    }
}

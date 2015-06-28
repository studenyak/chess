#include "board.h"
#include "piece_pool.h"
#include <iostream>

namespace chess
{
    Board::Board()
    {
    }

    void Board::setPiecePosition(const std::string &strAddr,
                                 const Piece* pPiece)
    {
        m_PiecePool[strAddr] = pPiece;
    }

    bool Board::movePiece(const std::string &strFromAddr,
                          const std::string &strToAddr)
    {
        std::map<std::string, const Piece*>::iterator it = m_PiecePool.find(strFromAddr);
        if(it == m_PiecePool.end())
        {
            std::cout << "No Piece found on this address" << std::endl;
            return false; // No Piece found on this address
        }

        std::map<std::string, const Piece*>::iterator itTo = m_PiecePool.find(strToAddr);
        if(itTo != m_PiecePool.end())
        {
            std::cout << "Address is busy" << std::endl;
            return false; // Address is busy
        }

        const Piece* pPiece = it->second;

        if(!pPiece->isMovingPossible(strFromAddr, strToAddr))
        {
            std::cout << "Movement is not possible" << std::endl;
            return false; // Movement is not possible.
        }

        m_PiecePool[strToAddr] = pPiece;
        m_PiecePool.erase(it);
        return true;
    }

    bool Board::movePiece(unsigned int fromIndex, unsigned int toIndex)
    {

        std::string str;
        return movePiece(indexToAddr(fromIndex,str),
                         indexToAddr(toIndex,str));
    }

    const char *Board::getPieceName(unsigned int nIndex)
    {
        std::string strAddr;
        indexToAddr(nIndex, strAddr);
        std::map<std::string, const Piece*>::const_iterator it = m_PiecePool.find(strAddr);
        if(it != m_PiecePool.end())
            return m_PiecePool[strAddr]->getName();

        return 0;
    }

    unsigned int Board::count() const
    {
        return m_PiecePool.size();
    }

    const char *Board::indexToAddr(unsigned int nIndex, std::string& strAddr)
    {
        char letter[3] = {'a' + nIndex % 8, '8' - nIndex / 8};
        strAddr.assign(letter);

        return strAddr.c_str();
    }
}


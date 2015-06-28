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
                          const std::string &strToAddr,
                          bool bWhiteTurn)
    {
        std::map<std::string, const Piece*>::iterator it = m_PiecePool.find(strFromAddr);
        if(it == m_PiecePool.end())
        {
            std::cout << "No Piece found on this address" << std::endl;
            return false; // No Piece found on this address
        }

        const Piece* pPiece = it->second;
        if(pPiece->isWhite() != bWhiteTurn)
        {
            std::cout << "Not your turn" << std::endl;
            return false;
        }

        std::vector<std::string> path;
        if(!pPiece->isMovingPossible(strFromAddr, strToAddr, path))
        {
            std::cout << "Movement is not possible" << std::endl;
            return false; // Movement is not possible.
        }

        const Piece* pBarier = barrierOnPath(path);
        if(pBarier)
        {
            std::cout << "Barrier on path: " << pBarier->getName() << std::endl;
            for(std::map<std::string, const Piece*>::const_iterator it = m_PiecePool.begin();
                it != m_PiecePool.end();
                it++)
            {
                const Piece* piece = it->second;
                std::cout << "[          ] key: " << it->first << " value: " << piece->getName() << std::endl;
            }
            return false;
        }

        std::map<std::string, const Piece*>::iterator itTo = m_PiecePool.find(strToAddr);
        if(itTo != m_PiecePool.end())
        {
            std::cout << "Kill this piece" << std::endl;
            m_PiecePool.erase(itTo);
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

    const Piece *Board::barrierOnPath(std::vector<std::string> &path)
    {
        for(int i = 0; i < path.size(); i++)
        {
            std::cout << path[i] << std::endl;
            std::map<std::string, const Piece*>::const_iterator it = m_PiecePool.find(path[i]);
            if(it != m_PiecePool.end())
                return it->second;
        }
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



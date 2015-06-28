#ifdef __GOOGLE_TEST__
#include <gtest/gtest.h>
#include "game.h"

using namespace chess;
TEST(Board, indexToAddr)
{
    Board board;
    std::string strAddr = "";
    board.indexToAddr(0,strAddr);

    EXPECT_STREQ(strAddr.c_str(), "a8");
    EXPECT_STRNE(board.indexToAddr(1,strAddr), "b1");
    EXPECT_STREQ(board.indexToAddr(63,strAddr), "h1");
    EXPECT_STRNE(board.indexToAddr(8,strAddr), "a2");
}

TEST(Game, move)
{
    Game game;
    game.start();
    Board& board = game.getBoard();
    EXPECT_TRUE(board.movePiece("a2","a3"));
}

TEST(Game, getImageByIndex)
{
    Game game;
    game.start();
    Board& board = game.getBoard();
    EXPECT_NE(board.m_PiecePool.size(), 0);
    EXPECT_STREQ(board.getPieceName(8), "pawn_black");

    for(std::map<std::string, const Piece*>::const_iterator it = board.m_PiecePool.begin();
        it != board.m_PiecePool.end();
        it ++)
    {
        const Piece* piece = it->second;
        std::cout << "[          ] key: " << it->first << " value: " << piece->getName() << std::endl;
    }
}


#endif

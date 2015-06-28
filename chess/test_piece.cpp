#ifdef __GOOGLE_TEST__
#include <gtest/gtest.h>
#include "piece_box.h"
#include <stdio.h>

using namespace chess;
TEST(PieceBox, creating)
{
    PieceBox box;
    box.create();
    EXPECT_EQ(box.count(), 32);
}

TEST(PieceBox, getName)
{
    PieceBox pieceBox;
    pieceBox.create();
    const PIECE_POOL& box = pieceBox.getPool();
    for(PIECE_POOL::const_iterator it = box.begin();
        it != box.end();
        it ++)
    {
        Piece* pPiece = it->second;
        if( it->first.find("2") != std::string::npos)
            EXPECT_STREQ(pPiece->getName(),"pawn_white");
        else if(it->first.find("7") != std::string::npos)
            EXPECT_STREQ(pPiece->getName(),"pawn_black");
        std::cout << "[          ] key: " << it->first << " value: " << pPiece->getName() << std::endl;
    }

}

TEST(Piece, strAddrToPos)
{
    Pos pos(std::string("a1"));
    EXPECT_EQ(pos.getX(), 0);EXPECT_EQ(pos.getY(), 0);

    pos = Pos(std::string("a2"));
    EXPECT_EQ(pos.getX(), 0);EXPECT_EQ(pos.getY(), 1
                                  );

    pos = Pos(std::string("c4"));
    EXPECT_EQ(pos.getX(), 2);EXPECT_EQ(pos.getY(), 3);

    pos = Pos(std::string("5g"));
    EXPECT_EQ(pos.getX(), -1);EXPECT_EQ(pos.getY(), -1);

    pos = Pos(std::string("h8"));
    EXPECT_EQ(pos.getX(), 7);EXPECT_EQ(pos.getY(), 7);


}

#endif

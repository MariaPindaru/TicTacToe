#include "gtest/gtest.h"
#include "TicTacToeLogic.h"

class SetPiece : public ::testing::Test
{
    void SetUp() override
    {
        logic.Configure(2, 2);
		logic.SetFirstPlayer("first");
		logic.SetSecondPlayer("second");
    }

public:
    TicTacToeLogic logic;
};

TEST_F(SetPiece, TestSetX)
{
    logic.MakeMoveAt(0, 0);

    ASSERT_TRUE(logic.GetPieceAt(0,0) == TicTacToeLogic::Piece::X);
}

TEST_F(SetPiece, TestSetO)
{
    logic.MakeMoveAt(1, 0);
    logic.MakeMoveAt(0, 0);

    ASSERT_TRUE(logic.GetPieceAt(0, 0) == TicTacToeLogic::Piece::O);
}
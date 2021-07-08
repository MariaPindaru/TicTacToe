#include "gtest/gtest.h"
#include "TicTacToeLogic.h"

class PlayerTest : public ::testing::Test
{
    void SetUp() override
    {
		logic = tictactoe::IGame::Produce();
		logic->Init(3, 3);
		logic->SetFirstPlayer("first");
		logic->SetSecondPlayer("second");
    }

public:
    tictactoe::IGame::Ptr logic;
};

TEST_F(PlayerTest, TestSetX)
{
    logic->MakeMoveAt(0, 0);

    ASSERT_TRUE(logic->GetPieceAt(0,0) == tictactoe::EPiece::X);
}

TEST_F(PlayerTest, TestSetO)
{
	logic->MakeMoveAt(1, 0);
	logic->MakeMoveAt(0, 0);

    ASSERT_TRUE(logic->GetPieceAt(0, 0) == tictactoe::EPiece::O);
}
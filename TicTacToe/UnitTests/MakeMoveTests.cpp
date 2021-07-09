#include "gtest/gtest.h"

#include "TicTacToeLogic.h"

class MakeMoveTest : public ::testing::Test
{
	void SetUp() override
	{
		logic = tictactoe::IGame::Produce();
		logic->Init(3, 3, EGameType::TwoPlayers);
		logic->SetFirstPlayer("first");
		logic->SetSecondPlayer("second");
	}

public:
	tictactoe::IGame::Ptr logic;
};

TEST_F(MakeMoveTest, TestMakeMove)
{
	ASSERT_TRUE(logic->MakeMoveAt(0, 2) == tictactoe::EMoveResult::Success);
	ASSERT_TRUE(logic->MakeMoveAt(0, 2) == tictactoe::EMoveResult::PositionOccupied);

	ASSERT_TRUE(logic->MakeMoveAt(0, 9) == tictactoe::EMoveResult::InvalidCoordinates);
}
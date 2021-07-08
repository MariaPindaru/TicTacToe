#include "gtest/gtest.h"
#include "TicTacToeLogic.h"


class GameTypeTest : public ::testing::Test
{
	void SetUp() override
	{
		logic = tictactoe::IGame::Produce();
	}

public:
	tictactoe::IGame::Ptr logic;
};

TEST_F(GameTypeTest, TestSinglePlayer)
{
	logic->Init(3, 3, EGameType::SinglePlayer);
	logic->SetFirstPlayer("first");
	logic->SetSecondPlayer("second");

	ASSERT_TRUE(logic->GetCurrentPlayer() == "first");

	logic->MakeMoveAt(0, 0);

	ASSERT_TRUE(logic->GetCurrentPlayer() == "first");
}


TEST_F(GameTypeTest, TestTwoPlayers)
{
	logic->Init(3, 3, EGameType::TwoPlayers);
	logic->SetFirstPlayer("first");
	logic->SetSecondPlayer("second");

	ASSERT_TRUE(logic->GetCurrentPlayer() == "first");

	logic->MakeMoveAt(0, 0);

	ASSERT_TRUE(logic->GetCurrentPlayer() == "second");
}

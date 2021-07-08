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

TEST_F(PlayerTest, TestSetFirstPlayer)
{
	ASSERT_TRUE(logic->GetFirstPlayer() == "first");
}

TEST_F(PlayerTest, TestSetSecondPlayer)
{
	ASSERT_TRUE(logic->GetSecondPlayer() == "second");
}

TEST_F(PlayerTest, TestCurrentPlayer)
{
	ASSERT_TRUE(logic->GetCurrentPlayer() == "first");

	logic->MakeMoveAt(0, 0);

	ASSERT_TRUE(logic->GetCurrentPlayer() == "second");
}
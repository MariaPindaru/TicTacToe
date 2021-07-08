#include "gtest/gtest.h"

#include "TicTacToeLogic.h"

class LineOrColumnWinTest : public ::testing::Test
{
    void SetUp() override
    {
        logic = tictactoe::IGame::Produce();
		logic->Init(3, 3);
		logic->SetFirstPlayer("first");
		logic->SetSecondPlayer("second");

		logic->MakeMoveAt(0, 0);
		logic->MakeMoveAt(2, 1);

		logic->MakeMoveAt(0, 1);
		logic->MakeMoveAt(2, 2);
    }

public:
    tictactoe::IGame::Ptr logic;
};

class DiagonalWinTest : public ::testing::Test
{
	void SetUp() override
	{
		logic = tictactoe::IGame::Produce();
		logic->Init(3, 3);
		logic->SetFirstPlayer("first");
		logic->SetSecondPlayer("second");

		logic->MakeMoveAt(0, 0);
		logic->MakeMoveAt(0, 2);

		logic->MakeMoveAt(2, 2);
		logic->MakeMoveAt(2, 0);
	}

public:
	tictactoe::IGame::Ptr logic;
};

TEST_F(LineOrColumnWinTest, TestLineXWin)
{         
    logic->MakeMoveAt(0, 2);

    ASSERT_TRUE(logic->GetGameState() == tictactoe::EGameState::XWon);
}

TEST_F(LineOrColumnWinTest, TestLineOWin)
{
	logic->MakeMoveAt(1, 2);
	logic->MakeMoveAt(2, 0);

	ASSERT_TRUE(logic->GetGameState() == tictactoe::EGameState::OWon);
}

TEST_F(LineOrColumnWinTest, TestColumnXWin)
{         
    logic->MakeMoveAt(1, 0);
    logic->MakeMoveAt(1, 1);
    logic->MakeMoveAt(2, 0);

    ASSERT_TRUE(logic->GetGameState() == tictactoe::EGameState::XWon);
}

TEST_F(LineOrColumnWinTest, TestColumnOWin)
{
	logic->MakeMoveAt(1, 0);
	logic->MakeMoveAt(1, 2);
	logic->MakeMoveAt(1, 1);
	logic->MakeMoveAt(0, 2);

	ASSERT_TRUE(logic->GetGameState() == tictactoe::EGameState::OWon);
}

TEST_F(DiagonalWinTest, TestRightDiagonalWin)
{
    logic->MakeMoveAt(1, 1);

    ASSERT_TRUE(logic->GetGameState() == tictactoe::EGameState::XWon);
}

TEST_F(DiagonalWinTest, TestLeftDiagonalWin)
{
	logic->MakeMoveAt(1, 0);
	logic->MakeMoveAt(1, 1);

	ASSERT_TRUE(logic->GetGameState() == tictactoe::EGameState::OWon);
}

TEST(Draw, TestDraw)
{
	tictactoe::IGame::Ptr logic = tictactoe::IGame::Produce();
	logic->Init(3, 3);
	logic->SetFirstPlayer("first");
	logic->SetSecondPlayer("second");

    for (int line = 0; line < 3; line += 2)
        for (int column = 0; column < 3; ++column) 
                logic->MakeMoveAt(line, column);

    for (int column = 0; column < 3; ++column)
        logic->MakeMoveAt(1, column);

    ASSERT_TRUE(logic->GetGameState() == tictactoe::EGameState::Draw);
}
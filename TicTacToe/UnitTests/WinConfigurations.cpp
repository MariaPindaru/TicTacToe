#include "gtest/gtest.h"
#include "TicTacToeLogic.h"

class GameOver : public ::testing::Test
{
    void SetUp() override
    {
        logic.Configure(3, 3);
        logic.SetFirstPlayer("first");
        logic.SetSecondPlayer("second");
    }

public:
    TicTacToeLogic logic;
};

TEST_F(GameOver, TestLineWin)
{
    logic.MakeMoveAt(0, 0);
    logic.MakeMoveAt(1, 0);

    logic.MakeMoveAt(0, 1);
    logic.MakeMoveAt(1, 1);

    logic.MakeMoveAt(0, 2);

    ASSERT_TRUE(logic.GetGameState() == TicTacToeLogic::GameState::Win);
}

TEST_F(GameOver, TestColumnWin)
{
    logic.MakeMoveAt(0, 0);
    logic.MakeMoveAt(0, 1);

    logic.MakeMoveAt(1, 0);
    logic.MakeMoveAt(1, 1);

    logic.MakeMoveAt(2, 0);

    ASSERT_TRUE(logic.GetGameState() == TicTacToeLogic::GameState::Win);
}

TEST_F(GameOver, TestRightDiagonalWin)
{
    logic.MakeMoveAt(0, 2);
    logic.MakeMoveAt(0, 1);

    logic.MakeMoveAt(1, 1);
    logic.MakeMoveAt(2, 1);

    logic.MakeMoveAt(2, 0);

    ASSERT_TRUE(logic.GetGameState() == TicTacToeLogic::GameState::Win);
}

TEST_F(GameOver, TestLeftDiagonalWin)
{
    logic.MakeMoveAt(0, 0);
    logic.MakeMoveAt(1, 0);

    logic.MakeMoveAt(1, 1);
    logic.MakeMoveAt(0, 1);

    logic.MakeMoveAt(2, 2);

    ASSERT_TRUE(logic.GetGameState() == TicTacToeLogic::GameState::Win);
}

TEST_F(GameOver, TestDraw)
{
    for (int line = 0; line < 3; line += 2)
        for (int column = 0; column < 3; ++column) 
                logic.MakeMoveAt(line, column);

    for (int column = 0; column < 3; ++column)
        logic.MakeMoveAt(1, column);

    ASSERT_TRUE(logic.GetGameState() == TicTacToeLogic::GameState::Draw);
}
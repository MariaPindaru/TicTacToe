#include "gtest/gtest.h"
#include "TicTacToeLogic.h"

extern ::testing::Environment* env;

class GameOver : public ::testing::Test
{
    void SetUp() override
    {
        logic.Configure(3, 3);
    }

public:
    TicTacToeLogic logic;
};

TEST_F(GameOver, TestLineWin)
{
    logic.MakeMoveAt(0, 0, true);
    logic.MakeMoveAt(0, 1, true);
    logic.MakeMoveAt(0, 2, true);

    ASSERT_TRUE(logic.GetGameState() == TicTacToeLogic::GameState::Win);
}

TEST_F(GameOver, TestColumnWin)
{
    logic.MakeMoveAt(0, 0, true);
    logic.MakeMoveAt(1, 0, true);
    logic.MakeMoveAt(2, 0, true);

    ASSERT_TRUE(logic.GetGameState() == TicTacToeLogic::GameState::Win);
}

TEST_F(GameOver, TestRightDiagonalWin)
{
    logic.MakeMoveAt(0, 2, true);
    logic.MakeMoveAt(1, 1, true);
    logic.MakeMoveAt(2, 0, true);

    ASSERT_TRUE(logic.GetGameState() == TicTacToeLogic::GameState::Win);
}

TEST_F(GameOver, TestLeftDiagonalWin)
{
    logic.MakeMoveAt(0, 0, true);
    logic.MakeMoveAt(1, 1, true);
    logic.MakeMoveAt(2, 2, true);

    ASSERT_TRUE(logic.GetGameState() == TicTacToeLogic::GameState::Win);
}

TEST_F(GameOver, TestDraw)
{
    TicTacToeLogic logic;
    logic.Configure(3, 3);
    int aux = 1;
    for (int line = 0; line < 3; ++line)
    {
        for (int column = 0; column < 3; ++column)
        {
            if ((aux + column) % 2 == 0)
            {
                logic.MakeMoveAt(line, column, true);
            }
            else
            {
                logic.MakeMoveAt(line, column, false);
            }
        }

        if (line % 2 == 1)
            aux = 0;
    }

    ASSERT_TRUE(logic.GetGameState() == TicTacToeLogic::GameState::Draw);
}
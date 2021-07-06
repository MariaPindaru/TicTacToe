#include "gtest/gtest.h"
#include "TicTacToeLogic.h"
#include "BaseEnviroment.h"

extern ::testing::Environment* env;

class WinConfiguration : public ::testing::Test
{
    void SetUp() override
    {
        logic.Configure(3, 3);
    }

    void test()
    {
        BaseEnvironment* my_env = (BaseEnvironment*)env;
    }

public:
    TicTacToeLogic logic;
};

TEST_F(WinConfiguration, TestLineWin)
{
    logic.SetPiece(0, 0, true);
    logic.SetPiece(0, 1, true);
    logic.SetPiece(0, 2, true);

    ASSERT_TRUE(logic.IsGameOver() == 0);
}

TEST_F(WinConfiguration, TestColumnWin)
{
    logic.SetPiece(0, 0, true);
    logic.SetPiece(1, 0, true);
    logic.SetPiece(2, 0, true);

    ASSERT_TRUE(logic.IsGameOver() == 0);
}

TEST_F(WinConfiguration, TestRightDiagonalWin)
{
    logic.SetPiece(0, 2, true);
    logic.SetPiece(1, 1, true);
    logic.SetPiece(2, 0, true);

    ASSERT_TRUE(logic.IsGameOver() == 0);
}

TEST_F(WinConfiguration, TestLeftDiagonalWin)
{
    logic.SetPiece(0, 0, true);
    logic.SetPiece(1, 1, true);
    logic.SetPiece(2, 2, true);

    ASSERT_TRUE(logic.IsGameOver() == 0);
}
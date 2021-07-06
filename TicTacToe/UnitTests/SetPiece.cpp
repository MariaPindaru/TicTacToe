#include "gtest/gtest.h"
#include "TicTacToeLogic.h"

class SetPiece : public ::testing::Test
{
    void SetUp() override
    {
        logic.Configure(2, 2);
    }

public:
    TicTacToeLogic logic;
};

TEST_F(SetPiece, TestSetX)
{
    logic.SetPiece(0, 0, true);

    auto board = std::move(logic.GetBoard());

    ASSERT_TRUE(board[0][0] == 'X');
}

TEST_F(SetPiece, TestSetY)
{
    logic.SetPiece(0, 0, false);

    auto board = std::move(logic.GetBoard());

    ASSERT_TRUE(board[0][0] == 'O');
}
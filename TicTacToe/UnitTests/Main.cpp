#include "gtest/gtest.h"
#include "TicTacToeLogic.h"


TEST(DrawConfiguration, TestDraw)
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
                logic.SetPiece(line, column, true);
            }
            else
            {
                logic.SetPiece(line, column, false);
            }
        }

        if (line % 2 == 1)
            aux = 0;
    }

    ASSERT_TRUE(logic.IsGameOver() == -1);
}

TEST(SetPiece, TestSetX)
{
    TicTacToeLogic logic;
    logic.Configure(3, 3);
    logic.SetPiece(0, 0, true);

    auto board = std::move(logic.GetBoard());

    ASSERT_TRUE(board[0][0] == 'X');
}

TEST(SetPiece, TestSetY)
{
    TicTacToeLogic logic;
    logic.Configure(3, 3);
    logic.SetPiece(0, 0, false);

    auto board = std::move(logic.GetBoard());

    ASSERT_TRUE(board[0][0] == 'O');
}

int main()
{

	return RUN_ALL_TESTS();
}
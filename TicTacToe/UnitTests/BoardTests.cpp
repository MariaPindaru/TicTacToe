#include "gtest/gtest.h"
#include "TicTacToeLogic.h"

TEST(Board, TestBoardConfig)
{
    TicTacToeLogic logic;
    logic.Configure(3, 3);
    
    auto board = std::move(logic.GetBoard());
    for (auto line : board)
    {
        for (auto pos : line)
            EXPECT_TRUE(pos == TicTacToeLogic::Piece::None);
    }
}

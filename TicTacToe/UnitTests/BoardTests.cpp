#include "gtest/gtest.h"
#include "TicTacToeLogic.h"

TEST(Board, TestBoardConfig)
{
    TicTacToeLogic logic;
    logic.Init(3, 3);
    
	int dim = logic.GetBoardSize();

	for (int line = 0; line < dim; ++line)
	{
		for (int column = 0; column < dim; ++column)
		{
			EXPECT_TRUE(logic.GetPieceAt(line, column) == TicTacToeLogic::Piece::None);
		}
	}
}

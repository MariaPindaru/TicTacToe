#include "gtest/gtest.h"
#include "TicTacToeLogic.h"

TEST(BoardTest, TestBoardConfig)
{
	tictactoe::IGame::Ptr logic = tictactoe::IGame::Produce();
	logic->Init(3, 3, EGameType::TwoPlayers);
	logic->SetFirstPlayer("first");
	logic->SetSecondPlayer("second");
    
	int dim = logic->GetBoardSize();

	for (int line = 0; line < dim; ++line)
	{
		for (int column = 0; column < dim; ++column)
		{
			EXPECT_TRUE(logic->GetPieceAt(line, column) == tictactoe::EPiece::None);
		}
	}
}

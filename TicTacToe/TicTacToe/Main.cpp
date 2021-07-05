#include <iostream>
#include "TicTacToeConsole.h"

int main()
{
	TicTacToeConsole game;

	game.ConfigureGame();
	//TicTacToeLogic logic(4, 2);
	//logic.SetX(2, 0);
	//logic.SetX(1, 1);
	//auto board = logic.GetBoard();

	//for (int line = 0; line < board.size(); ++line)
	//{
	//	for (int column = 0; column < board.size(); ++column)
	//	{
	//		std::cout << board[line][column] << " ";
	//	}
	//	std::cout << std::endl;
	//}

	//if (logic.IsGameOver())
	//	std::cout << "Game over";
	return 0;
}
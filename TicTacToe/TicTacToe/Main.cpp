#include <iostream>
#include "TicTacToeLogic.h"
int main()
{
	TicTacToeLogic logic(4, 2);
	auto board = logic.GetBoard();
	for (int line = 0; line < board.size(); ++line)
	{
		for (int column = 0; column < board.size(); ++column)
		{
			std::cout << board[line][column] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
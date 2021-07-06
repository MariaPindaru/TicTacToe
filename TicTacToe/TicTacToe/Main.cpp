#include <iostream>
#include "TicTacToeConsole.h"

int main()
{
	TicTacToeConsole game;

	game.ConfigureGame();
	game.Run();

	return 0;
}
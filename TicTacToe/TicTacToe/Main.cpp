#include <iostream>
#include "TicTacToeConsole.h"
#include "TicTacToeLogic.h"

int main()
{
	TicTacToeConsole game;

	game.ConfigureGame();
	game.Run();

	return 0;
}
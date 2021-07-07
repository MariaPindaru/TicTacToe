#pragma once
#include "GameAPI.h"

class TicTacToeConsole
{
public:
	void Run();

private:
	void PrintBoard(std::shared_ptr<tictactoe::IGame>);
};


#pragma once
#include "GameAPI.h"

class TicTacToeConsole
{
public:
	void Run();

private:
	void PrintBoard(tictactoe::IGame::Ptr);
};


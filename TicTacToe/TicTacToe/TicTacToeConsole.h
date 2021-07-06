#pragma once
#include "TicTacToeLogic.h"

class TicTacToeConsole
{
public:
	TicTacToeConsole();
	void ConfigureGame();
	void Run();

private:
	void PrintBoard();

private:
	TicTacToeLogic m_bussinesLogic;
};


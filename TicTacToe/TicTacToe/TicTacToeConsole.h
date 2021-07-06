#pragma once
#include "TicTacToeLogic.h"

class TicTacToeConsole
{
public:
	void ConfigureGame();
	void Run();

private:
	void PrintBoard();

private:
	TicTacToeLogic m_bussinesLogic;
};


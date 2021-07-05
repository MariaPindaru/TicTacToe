#pragma once
#include "TicTacToeLogic.h"

class TicTacToeConsole
{
public:
	TicTacToeConsole();
	void ConfigureGame();
private:
	TicTacToeLogic m_bussinesLogic;
};


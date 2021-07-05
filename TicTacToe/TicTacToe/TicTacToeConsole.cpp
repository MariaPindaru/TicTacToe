#include "TicTacToeConsole.h"
#include <iostream>

TicTacToeConsole::TicTacToeConsole()
{
}

void TicTacToeConsole::ConfigureGame()
{
	while (true)
	{
		int dim, winCount;
		std::cout << "Board dimension: ";
		std::cin >> dim;
		std::cout << "Win count: ";
		std::cin >> winCount;
		try
		{
			this->m_bussinesLogic.Configure(dim, winCount);
			break;
		}
		catch (const char* exception)
		{
			std::cerr << exception << std::endl;
			std::cerr << "Try again... " << std::endl;
		}
	}
}

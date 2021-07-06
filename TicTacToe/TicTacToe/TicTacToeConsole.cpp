#include "TicTacToeConsole.h"
#include <iostream>
#include "Player.h"

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

void TicTacToeConsole::Run()
{
	std::string firstName, secondName;
	std::cout << "First player: ";
	std::cin >> firstName;
	
	do
	{
		std::cout << "Second player: ";
		std::cin >> secondName;
	} while (firstName == secondName);

	Player firstPlayer(firstName), secondPlayer(secondName);

	bool isXTurns = true;
	Player currentPlayer;
	PrintBoard();
	while (!m_bussinesLogic.IsGameOver())
	{
		
		currentPlayer = isXTurns == true ? firstPlayer : secondPlayer;
		std::pair<int, int> pos;
		while (true)
		{
			std::cout << currentPlayer.GetName() << ", it's your turn" << std::endl;
			try
			{
				pos = currentPlayer.SelectPosition(m_bussinesLogic.GetBoardSize());
				break;
			}
			catch (const char* exception)
			{
				std::cerr << exception << std::endl;
				std::cerr << "Try again... " << std::endl;
			}
		}
		while (true)
		{
			try
			{
				m_bussinesLogic.SetPiece(pos.first, pos.second, isXTurns);
				break;
			}
			catch (const char* exception)
			{
				std::cerr << exception << std::endl;
				std::cerr << "Try again... " << std::endl;
			}
			PrintBoard();
		}

		isXTurns = !isXTurns;
	}

	if (currentPlayer == firstPlayer)
		std::cout << firstPlayer.GetName() << " won!" << std::endl;
	else
		std::cout << secondPlayer.GetName() << " won!" << std::endl;
}

void TicTacToeConsole::PrintBoard()
{
	auto board = std::move(m_bussinesLogic.GetBoard());

	for (int line = 0; line < board.size(); ++line)
	{
		for (int column = 0; column < board.size(); ++column)
		{
			std::cout << board[line][column] << "  ";
		}
		std::cout << std::endl;
	}
}

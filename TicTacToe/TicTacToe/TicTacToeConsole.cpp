#include "TicTacToeConsole.h"
#include <iostream>
#include "Player.h"

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

	m_bussinesLogic.SetFirstPlayer(firstName);
	m_bussinesLogic.SetSecondPlayer(secondName);

	PrintBoard();

	while (m_bussinesLogic.GetGameState() == TicTacToeLogic::GameState::Playing)
	{
		std::pair<int, int> pos;
		while (true)
		{

			std::cout << m_bussinesLogic.GetCurrentPlayer() << ", it's your turn" << std::endl;
			std::cout << "Select position: ";
			std::cin >> pos.first >> pos.second;
			try
			{
				m_bussinesLogic.MakeMoveAt(pos.first, pos.second);
				break;
			}
			catch (const char* exception)
			{
				std::cerr << exception << std::endl;
				std::cerr << "Try again... " << std::endl;
			}
		}

		system("cls");
		PrintBoard();
	}

	if (m_bussinesLogic.GetGameState() == TicTacToeLogic::GameState::Draw)
	{
		std::cout<<"Draw :)" << std::endl;
	}
	else 
	{
		std::cout << m_bussinesLogic.GetCurrentPlayer() << " won!" << std::endl;
	}
	
}

void TicTacToeConsole::PrintBoard()
{
	int dim = m_bussinesLogic.GetBoardSize();

	for (int line = 0; line < dim; ++line)
	{
		for (int column = 0; column < dim; ++column)
		{
			char aux;
			switch (m_bussinesLogic.GetPieceAt(line, column))
			{
			case TicTacToeLogic::Piece::X:
				aux = 'X';
				break;
			case TicTacToeLogic::Piece::O:
				aux = 'O';
				break;
			default:
				aux = '*';
				break;
			}
			std::cout << aux << "  ";
		}
		std::cout << std::endl << std::endl;
	}
}

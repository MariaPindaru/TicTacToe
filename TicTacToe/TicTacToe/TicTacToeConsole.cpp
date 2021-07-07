#include "TicTacToeConsole.h"
#include <iostream>
#include "Player.h"

void TicTacToeConsole::Run()
{
	auto bussinesLogic = tictactoe::IGame::Produce();

	while (true)
	{
		int dim, winCount;
		std::cout << "Board dimension: ";
		std::cin >> dim;
		std::cout << "Win count: ";
		std::cin >> winCount;
		try
		{
			bussinesLogic->Configure(dim, winCount);
			break;
		}
		catch (const char* exception)
		{
			std::cerr << exception << std::endl;
			std::cerr << "Try again... " << std::endl;
		}
	}

	std::string firstName, secondName;
	std::cout << "First player: ";
	std::cin >> firstName;
	
	do
	{
		std::cout << "Second player: ";
		std::cin >> secondName;
	} while (firstName == secondName);

	

	bussinesLogic->SetFirstPlayer(firstName);
	bussinesLogic->SetSecondPlayer(secondName);

	PrintBoard(bussinesLogic);

	while (bussinesLogic->GetGameState() == tictactoe::GameState::Playing)
	{
		std::pair<int, int> pos;
		while (true)
		{

			std::cout << bussinesLogic->GetCurrentPlayer() << ", it's your turn" << std::endl;
			std::cout << "Select position: ";
			std::cin >> pos.first >> pos.second;
			try
			{
				bussinesLogic->MakeMoveAt(pos.first, pos.second);
				break;
			}
			catch (const char* exception)
			{
				std::cerr << exception << std::endl;
				std::cerr << "Try again... " << std::endl;
			}
		}

		system("cls");
		PrintBoard(bussinesLogic);
	}

	if (bussinesLogic->GetGameState() == tictactoe::GameState::Draw)
		std::cout<<"Draw :)" << std::endl;
	else 
		std::cout << bussinesLogic->GetCurrentPlayer() << " won!" << std::endl;
}

void TicTacToeConsole::PrintBoard(std::shared_ptr<tictactoe::IGame> bussinesLogic)
{
	int dim = bussinesLogic->GetBoardSize();

	for (int line = 0; line < dim; ++line)
	{
		for (int column = 0; column < dim; ++column)
		{
			char aux;
			switch (bussinesLogic->GetPieceAt(line, column))
			{
			case tictactoe::Piece::X:
				aux = 'X';
				break;
			case tictactoe::Piece::O:
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

#include "TicTacToeConsole.h"
#include <iostream>

void TicTacToeConsole::Run()
{
	tictactoe::IGame::Ptr bussinesLogic = tictactoe::IGame::Produce();

	while (true)
	{
		int dim, winCount;
		std::cout << "Board dimension: ";
		std::cin >> dim;
		std::cout << "Win count: ";
		std::cin >> winCount;
		try
		{
			bussinesLogic->Init(dim , winCount);
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
		do 
		{
			std::cout << bussinesLogic->GetCurrentPlayer() << ", it's your turn" << std::endl;
			std::cout << "Select position: ";
			std::cin >> pos.first >> pos.second;
		} while (bussinesLogic->MakeMoveAt(pos.first, pos.second) != tictactoe::EMoveResult::Success);

		system("cls");
		PrintBoard(bussinesLogic);
	}

	switch (bussinesLogic->GetGameState())
	{
	default:
		break;
	case tictactoe::GameState::XWon:
		std::cout << bussinesLogic->GetFirstPlayer() << " won!" << std::endl;
		break;
	case tictactoe::GameState::OWon:
		std::cout << bussinesLogic->GetSecondPlayer() << " won!" << std::endl;
		break;
	case tictactoe::GameState::Draw:
		std::cout << "Draw! :)" << std::endl;
		break;
	}
}

void TicTacToeConsole::PrintBoard(tictactoe::IGame::Ptr bussinesLogic)
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

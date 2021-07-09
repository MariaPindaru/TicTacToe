#include "TicTacToeConsole.h"
#include <iostream>

void TicTacToeConsole::Run()
{
	while (true)
	{
		tictactoe::IGame::Ptr bussinessLogic = tictactoe::IGame::Produce();

		while (true)
		{
			int dim, winCount;
			std::string gameMode, whoIsFirst;
			std::cout << "Board dimension: ";
			std::cin >> dim;
			std::cout << "Win count: ";
			std::cin >> winCount;
			std::cout << "VS computer? (y/n) ";
			std::cin >> gameMode;

			if (gameMode == "y")
			{
				std::cout << "Do you want to be X? (y/n) ";
				std::cin >> whoIsFirst;
			}

			try
			{
				bussinessLogic->Init(dim, winCount, gameMode == "y" ? tictactoe::EGameType::SinglePlayer : tictactoe::EGameType::TwoPlayers, whoIsFirst == "y" ? false : true);
				break;
			}
			catch (const char* exception)
			{
				std::cerr << exception << std::endl;
				std::cerr << "Try again... " << std::endl;
			}
		}

		int difficulty;
		do {
			std::cout << "Select difficulty: " << std::endl << "1 -> easy" << std::endl << "2 -> medium" << std::endl;
			std::cin >> difficulty;
		} while (difficulty != 1 && difficulty != 2);
		bussinessLogic->SetStrategy(static_cast<tictactoe::EStrategy>(difficulty - 1));

		std::string firstName, secondName;
		std::cout << "First player: ";
		std::cin >> firstName;

		do
		{
			std::cout << "Second player: ";
			std::cin >> secondName;
		} while (firstName == secondName);

		bussinessLogic->SetFirstPlayer(firstName);
		bussinessLogic->SetSecondPlayer(secondName);

		PrintBoard(bussinessLogic);

		while (bussinessLogic->GetGameState() == tictactoe::EGameState::Playing)
		{
			std::pair<int, int> pos;
			do
			{
				std::cout << bussinessLogic->GetCurrentPlayer() << ", it's your turn" << std::endl;
				std::cout << "Select position: ";
				std::cin >> pos.first >> pos.second;
			} while (bussinessLogic->MakeMoveAt(pos.first, pos.second) != tictactoe::EMoveResult::Success);

			system("cls");
			PrintBoard(bussinessLogic);
		}


		switch (bussinessLogic->GetGameState())
		{
		default:
			break;
		case tictactoe::EGameState::XWon:
			std::cout << bussinessLogic->GetFirstPlayer() << " won!" << std::endl;
			break;
		case tictactoe::EGameState::OWon:
			std::cout << bussinessLogic->GetSecondPlayer() << " won!" << std::endl;
			break;
		case tictactoe::EGameState::Draw:
			std::cout << "Draw! :)" << std::endl;
			break;
		}
		
		std::string playAgain;
		std::cout << "Do you want to play again? (y/n) ";
		std::cin >>playAgain;

		if (playAgain != "y")
			break;

		system("cls");
	}
	

	

}

void TicTacToeConsole::PrintBoard(tictactoe::IGame::Ptr bussinessLogic)
{
	int dim = bussinessLogic->GetBoardSize();

	for (int line = 0; line < dim; ++line)
	{
		for (int column = 0; column < dim; ++column)
		{
			char aux;
			switch (bussinessLogic->GetPieceAt(line, column))
			{
			case tictactoe::EPiece::X:
				aux = 'X';
				break;
			case tictactoe::EPiece::O:
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

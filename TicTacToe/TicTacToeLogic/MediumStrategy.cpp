#include "MediumStrategy.h"

#include <ctime>

std::pair<int, int> MediumStrategy::GetMove(const std::vector<std::vector<tictactoe::EPiece>>& board, int winCount)
{
	srand((unsigned)time(0));

	int x = 0, o = 0;
	std::vector<std::pair<int, int>> possiblePositions;

	for (int line = 0; line < board.size(); ++line)
		for (int column = 0; column < board.size(); ++column)
			switch (board[line][column])
			{
			case tictactoe::EPiece::None:
				possiblePositions.push_back(std::make_pair(line, column));
				break;
			case tictactoe::EPiece::X:
				++x;
				break;
			case tictactoe::EPiece::O:
				++o;
				break;
			default:
				break;
			}

	tictactoe::EPiece pieceToPlace = x > o ? tictactoe::EPiece::O : tictactoe::EPiece::X;

	//line
	for (int line = 0; line < board.size(); ++line)
	{
		int count = 0;
		for (int column = 0; column < board.size(); ++column)
		{
			if (board[line][column] != pieceToPlace && board[line][column] != tictactoe::EPiece::None)
				++count;
			else
				count = 0;

			if (count == winCount - 1)
			{
				if (column < board.size() - 1 && board[line][column + 1] == tictactoe::EPiece::None)
					return std::make_pair(line, column + 1);

				if (column == board.size() - 1 && board[line][column - count] == tictactoe::EPiece::None)
					return std::make_pair(line, column - count);

				break;
			}
		}
	}

	//column
	for (int column = 0; column < board.size(); ++column)
	{
		int count = 0;
		for (int line = 0; line < board.size(); ++line)
		{
			if (board[line][column] != pieceToPlace && board[line][column] != tictactoe::EPiece::None)
				++count;
			else
				count = 0;

			if (count == winCount - 1)
			{
				if (line < board.size() - 1 && board[line + 1][column] == tictactoe::EPiece::None)
					return std::make_pair(line + 1, column);

				if (line == board.size() - 1 && board[line - count][column] == tictactoe::EPiece::None)
					return std::make_pair(line - count, column);

				break;
			}
		}
	}

	//diagonal
	for (int line = 0; line < board.size(); ++line)
	{
		for (int column = 0; column < board.size(); ++column)
		{
			if (board[line][column] != pieceToPlace && board[line][column] != tictactoe::EPiece::None)
			{
				int count = 1;
				for (int aux = 1; line + aux < board.size() && column + aux < board.size(); ++aux)
				{
					if (board[line + aux][column + aux] != pieceToPlace && board[line + aux][column + aux] != tictactoe::EPiece::None)
						++count;
					else
						count = 0;

					if (count == winCount - 1)
					{
						if (line + aux < board.size() - 1 && column + aux < board.size() - 1 && board[line + aux + 1][column + aux + 1] == tictactoe::EPiece::None)
							return std::make_pair(line + aux + 1, column + aux + 1);

						if (line + aux - count > 0 && column + aux - count > 0 && board[line + aux - count][column + aux - count] == tictactoe::EPiece::None)
							return std::make_pair(line + aux - count, column + aux - count);

						break;
					}
				}

				count = 1;
				for (int aux = 1; line + aux < board.size() && column - aux > 0; ++aux)
				{
					if (board[line + aux][column - aux] != pieceToPlace && board[line + aux][column - aux] != tictactoe::EPiece::None)
						++count;
					else
						count = 0;

					if (count == winCount - 1)
					{
						if (line + aux < board.size() - 1 && column - aux > 0 && board[line + aux + 1][column - aux - 1] == tictactoe::EPiece::None)
							return std::make_pair(line + aux + 1, column - aux - 1);

						if (line + aux - count > 0 && column - aux - count > 0 && board[line + aux - count][column - aux - count] == tictactoe::EPiece::None)
							return std::make_pair(line + aux - count, column - aux - count);

						break;
					}
				}
			}
		}
	}

	return possiblePositions.at(rand() % possiblePositions.size());
}

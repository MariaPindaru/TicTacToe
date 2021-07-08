#include "EasyStrategy.h"

#include <vector>
#include <ctime>

std::pair<int, int> EasyStrategy::GetMove(const std::vector<std::vector<tictactoe::EPiece>>& board, int winCount)
{
	srand((unsigned)time(0));

	std::vector<std::pair<int, int>> possiblePositions;

	for (int line = 0; line < board.size(); ++line)
		for (int column = 0; column < board.size(); ++column)
			if (board[line][column] == tictactoe::EPiece::None)
				possiblePositions.push_back(std::make_pair(line, column));

	return possiblePositions.at(rand() % possiblePositions.size());
}

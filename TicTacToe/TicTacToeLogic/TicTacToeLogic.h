#pragma once
#include <vector>
class TicTacToeLogic
{
public:
	enum class Piece
	{
		None,
		X,
		O
	};

	enum class GameState
	{
		None,
		Playing,
		Win
	};
	TicTacToeLogic();

	void Configure(int dim, int win);
	int GetBoardSize() const;

	void SetPiece(int line, int column, bool placeX);

	std::vector<std::vector<char>> GetBoard() const;

	bool IsGameOver();

private:
	void CheckGameState(int line, int column);
	bool GameWon(int line, int column);
	bool CheckColumn(int line, int column);
	bool CheckLine(int line, int column);
	bool CheckRightDiagonal(int line, int column);
	bool CheckLeftDiagonal(int line, int column);

private:
	std::vector<std::vector<Piece>> m_board;
	GameState m_state;
	int m_winCount;
};

#pragma once
#include <vector>
#include "Player.h"

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
		Win,
		Draw
	};

	TicTacToeLogic();

	void Configure(int dim, int win);
	void SetFirstPlayer(const std::string& name);
	void SetSecondPlayer(const std::string& name);
	int GetBoardSize() const;
	std::string GetCurrentPlayer() const;

	 Piece GetPieceAt(int line, int column) const;

	void MakeMoveAt(int line, int column);

	GameState GetGameState() const;

private:
	void CheckGameState(int line, int column);
	bool GameWon(int line, int column);
	bool CheckColumn(int line, int column);
	bool CheckLine(int line, int column);
	bool CheckRightDiagonal(int line, int column);
	bool CheckLeftDiagonal(int line, int column);
	bool IsBoardFull();

private:
	std::vector<std::vector<Piece>> m_board;
	GameState m_state;
	int m_winCount;
	Player m_firstPlayer;
	Player m_secondPlayer;
};

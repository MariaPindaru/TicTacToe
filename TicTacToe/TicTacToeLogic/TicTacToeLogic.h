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

	void Configure(int, int);
	void SetFirstPlayer(const std::string&);
	void SetSecondPlayer(const std::string&);
	int GetBoardSize() const;
	std::string GetCurrentPlayer() const;

	 Piece GetPieceAt(int, int) const;

	void MakeMoveAt(int, int);

	GameState GetGameState() const;

private:
	void CheckGameState(int, int);
	bool GameWon(int, int);
	bool CheckColumn(int, int);
	bool CheckLine(int, int);
	bool CheckRightDiagonal(int, int);
	bool CheckLeftDiagonal(int, int);
	bool IsBoardFull();

private:
	std::vector<std::vector<Piece>> m_board;
	GameState m_state;
	int m_winCount;
	Player m_firstPlayer;
	Player m_secondPlayer;
};

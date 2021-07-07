#pragma once
#include <vector>
#include "Player.h"
#include "GameAPI.h"

using namespace tictactoe;

class TicTacToeLogic : public IGame
{
public:
	TicTacToeLogic();

	void Configure(int, int) override;
	void SetFirstPlayer(const std::string&) override;
	void SetSecondPlayer(const std::string&) override;
	int GetBoardSize() const override;
	std::string GetCurrentPlayer() const override;

	 Piece GetPieceAt(int, int) const override;

	void MakeMoveAt(int, int) override;

	GameState GetGameState() const override;

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

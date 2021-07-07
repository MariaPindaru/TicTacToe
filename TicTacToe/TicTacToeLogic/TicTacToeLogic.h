#pragma once

#include <vector>
#include <memory>

#include "Player.h"
#include "API/GameAPI.h"

using namespace tictactoe;

class TicTacToeLogic : public IGame
{
public:
	TicTacToeLogic();

	void Init(int, int) override;

	void SetFirstPlayer(const std::string&) override;
	void SetSecondPlayer(const std::string&) override;
	std::string GetFirstPlayer() const override;
	std::string GetSecondPlayer() const override;

	int GetBoardSize() const override;
	std::string GetCurrentPlayer() const override;
	 Piece GetPieceAt(int, int) const override;

	 void SetStrategy(EStrategy strategyType) override;
	 //void SetStrategy(std::shared_ptr<IStrategy> newStrategy) override;

	 EMoveResult MakeMoveAt(int, int) override;

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

	std::shared_ptr<IStrategy> m_strategy;
};

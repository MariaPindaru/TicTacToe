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
		Playing,
		XWon,
		OWon
	};

	TicTacToeLogic(int dim, int win);

	void SetX(int line, int column);

	void SetO(int line, int column);

	std::vector<std::vector<char>> GetBoard() const;

private:
	GameState CheckGameState();

	bool XWon();
	bool OWon();

private:
	std::vector<std::vector<Piece>> m_board;
	GameState state;
};

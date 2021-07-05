// TicTacToeLogic.cpp : Defines the functions for the static library.
//

#include "pch.h"

#include "TicTacToeLogic.h"


TicTacToeLogic::TicTacToeLogic(int dim, int win)
{
	if (dim < win)
		throw "Invalid dimensions!";
	for (int line = 0; line < dim; ++line)
	{
		std::vector<Piece> aux;
		for (int column = 0; column < dim; ++column)
		{
			aux.push_back(Piece::None);
		}
		m_board.push_back(aux);
	}
	state = GameState::Playing;
}

void TicTacToeLogic::SetX(int line, int column)
{
	if (line < 0 || column < 0 || line >= m_board.size() || column >= m_board.size())
		throw "Invalid position";
	if (m_board[line][column] != Piece::None)
		throw "Position unavailable!";
	m_board[line][column] = Piece::X;
}

void TicTacToeLogic::SetO(int line, int column)
{
	if (line < 0 || column < 0 || line >= m_board.size() || column >= m_board.size())
		throw "Invalid position";
	if (m_board[line][column] != Piece::None)
		throw "Position unavailable!";
	m_board[line][column] = Piece::O;
}

std::vector<std::vector<char>> TicTacToeLogic::GetBoard() const
{
	std::vector<std::vector<char>> board;
	for (int line = 0; line < m_board.size(); ++line)
	{
		std::vector<char> aux;
		for (int column = 0; column < m_board.size(); ++column)
		{
			if (m_board[line][column] == Piece::None)
				aux.push_back('*');
			else if (m_board[line][column] == Piece::X)
				aux.push_back('X');
			else
				aux.push_back('O');
		}
		board.push_back(aux);
	}
	return board;
}

TicTacToeLogic::GameState TicTacToeLogic::CheckGameState()
{
	if (XWon())
		return GameState::XWon;
	if (OWon())
		return GameState::OWon;
	return GameState::Playing;
}

bool TicTacToeLogic::XWon()
{
	return false;
}

bool TicTacToeLogic::OWon()
{
	return false;
}

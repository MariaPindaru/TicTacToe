
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
	m_winCount = win;
	m_state = GameState::Playing;
}

void TicTacToeLogic::SetX(int line, int column)
{
	if (line < 0 || column < 0 || line >= m_board.size() || column >= m_board.size())
		throw "Invalid position";
	if (m_board[line][column] != Piece::None)
		throw "Position unavailable!";
	m_board[line][column] = Piece::X;
	CheckGameState(line, column);
}

void TicTacToeLogic::SetO(int line, int column)
{
	if (line < 0 || column < 0 || line >= m_board.size() || column >= m_board.size())
		throw "Invalid position";
	if (m_board[line][column] != Piece::None)
		throw "Position unavailable!";
	m_board[line][column] = Piece::O;
	CheckGameState(line, column);
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

bool TicTacToeLogic::IsGameOver()
{
	if (m_state == GameState::OWon || m_state == GameState::XWon)
		return true;
	return false;
}

void TicTacToeLogic::CheckGameState(int line, int column)
{
	if (GameWon(line, column))
	{
		if (m_board[line][column] == Piece::X)
			m_state = GameState::XWon;
		else
			m_state = GameState::OWon;
		return;
	}
		
	m_state = GameState::Playing;
}

bool TicTacToeLogic::GameWon(int lineIndex, int columnIndex)
{
	if (CheckLine(lineIndex, columnIndex) || CheckColumn(lineIndex, columnIndex) ||
		CheckRightDiagonal(lineIndex, columnIndex) || CheckLeftDiagonal(lineIndex, columnIndex))
		return true;

	return false;

}

bool TicTacToeLogic::CheckColumn(int lineIndex, int columnIndex)
{
	int count = 0;
	Piece piece = m_board[lineIndex][columnIndex];
	for (int line = lineIndex; line >= 0; --line)
	{
		if (m_board[line][columnIndex] == piece)
			++count;
		else
			break;
		if (count == m_winCount)
			return true;
	}
	for (int line = lineIndex + 1; line < m_board.size(); ++line)
	{
		if (m_board[line][columnIndex] == piece)
			++count;
		else
			break;
		if (count == m_winCount)
			return true;
	}
	return false;
}

bool TicTacToeLogic::CheckLine(int lineIndex, int columnIndex)
{
	int count = 0;
	Piece piece = m_board[lineIndex][columnIndex];
	for (int column = lineIndex; column >= 0; --column)
	{
		if (m_board[lineIndex][column] == piece)
			++count;
		else
			break;
		if (count == m_winCount)
			return true;
	}
	for (int column = columnIndex + 1; column < m_board.size(); ++column)
	{
		if (m_board[lineIndex][column] == piece)
			++count;
		else
			break;
		if (count == m_winCount)
			return true;
	}
	return false;
}

bool TicTacToeLogic::CheckRightDiagonal(int lineIndex, int columnIndex)
{
	int count = 0;
	Piece piece = m_board[lineIndex][columnIndex];

	for (int line = lineIndex, column = columnIndex; line >= 0 && column < m_board.size(); --line, ++column)
	{
		if (m_board[line][column] == piece)
			++count;
		else
			break;
		if (count == m_winCount)
			return true;
	}
	for (int line = lineIndex + 1, column = columnIndex - 1; column >= 0 && line < m_board.size(); ++line, --column)
	{
		if (m_board[line][column] == piece)
			++count;
		else
			break;
		if (count == m_winCount)
			return true;
	}
	return false;
}

bool TicTacToeLogic::CheckLeftDiagonal(int lineIndex, int columnIndex)
{
	int count = 0;
	Piece piece = m_board[lineIndex][columnIndex];

	for (int line = lineIndex, column = columnIndex; line < m_board.size() && column < m_board.size(); ++line, ++column)
	{
		if (m_board[line][column] == piece)
			++count;
		else
			break;
		if (count == m_winCount)
			return true;
	}
	for (int line = lineIndex - 1, column = columnIndex - 1; column >= 0 && line >= 0 ; --line, --column)
	{
		if (m_board[line][column] == piece)
			++count;
		else
			break;
		if (count == m_winCount)
			return true;
	}

	return false;
}


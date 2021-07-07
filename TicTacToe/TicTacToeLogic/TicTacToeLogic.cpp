
#include "TicTacToeLogic.h"


TicTacToeLogic::TicTacToeLogic()
	: m_state(GameState::None)
	, m_winCount(2)
{}

void TicTacToeLogic::Init(int dim, int win)
{
	if (dim < win || win < 2 || dim < 2)
		throw "Invalid dimensions!";

	for (int line = 0; line < dim; ++line)
	{
		std::vector<Piece> aux(dim, Piece::None);
		m_board.push_back(aux);
	}
	m_winCount = win;
	m_state = GameState::Playing;
}

void TicTacToeLogic::SetFirstPlayer(const std::string& name)
{
	m_firstPlayer.SetName(name);
	m_firstPlayer.SetIsMyTurn(true);
}

void TicTacToeLogic::SetSecondPlayer(const std::string& name)
{
	m_secondPlayer.SetName(name);
}

std::string TicTacToeLogic::GetFirstPlayer() const
{
	return m_firstPlayer.GetName();
}

std::string TicTacToeLogic::GetSecondPlayer() const
{
	return m_secondPlayer.GetName();
}

int TicTacToeLogic::GetBoardSize() const
{
	return m_board.size();
}

std::string TicTacToeLogic::GetCurrentPlayer() const
{
	return m_firstPlayer.GetIsMyTurn() ? m_firstPlayer.GetName() : m_secondPlayer.GetName();
}

tictactoe::Piece TicTacToeLogic::GetPieceAt(int line, int column) const
{
	return m_board[line][column];
}

tictactoe::EMoveResult TicTacToeLogic::MakeMoveAt(int line, int column)
{
	if (line < 0 || column < 0 || line >= m_board.size() || column >= m_board.size())
		return tictactoe::EMoveResult::InvalidCoordinates;

	if (m_board[line][column] != Piece::None)
		return tictactoe::EMoveResult::PositionOccupied;

	m_board[line][column] = m_firstPlayer.GetIsMyTurn() ? Piece::X : Piece::O;

	CheckGameState(line, column);

	return tictactoe::EMoveResult::Success;
}

tictactoe::GameState TicTacToeLogic::GetGameState() const
{
	return m_state;
}

void TicTacToeLogic::CheckGameState(int line, int column)
{
	if (GameWon(line, column))
		m_state = m_firstPlayer.GetIsMyTurn() ? GameState::XWon : GameState::OWon;
	else if (IsBoardFull())
		m_state = GameState::Draw;
	else
	{
		m_state = GameState::Playing;
		m_firstPlayer.ChangeTurn();
		m_secondPlayer.ChangeTurn();
	}
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
	for (int column = columnIndex; column >= 0; --column)
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
	for (int line = lineIndex - 1, column = columnIndex - 1; column >= 0 && line >= 0; --line, --column)
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

bool TicTacToeLogic::IsBoardFull()
{
	for (const auto& line : m_board)
	{
		for (const auto& position : line)
		{
			if (position == Piece::None)
				return false;
		}
	}
	return true;
}

tictactoe::IGame::Ptr IGame::Produce()
{
	return std::make_shared<TicTacToeLogic>();
}


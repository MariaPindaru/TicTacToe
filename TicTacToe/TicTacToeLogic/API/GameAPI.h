#pragma once

#include <string>

namespace tictactoe
{
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
		XWon,
		OWon,
		Draw
	};

	enum class EMoveResult
	{
		Success = 0,
		PositionOccupied,
		InvalidCoordinates
	};

	class IGame
	{
	public:
		using Ptr = std::shared_ptr<IGame>;
		 
		virtual void Init(int, int) = 0;

		virtual void SetFirstPlayer(const std::string&) = 0;
		virtual void SetSecondPlayer(const std::string&) = 0;
		virtual std::string GetFirstPlayer() const = 0;
		virtual std::string GetSecondPlayer() const = 0;

		virtual int GetBoardSize() const = 0;
		virtual std::string GetCurrentPlayer() const = 0;
		virtual Piece GetPieceAt(int, int) const = 0;
		virtual GameState GetGameState() const = 0;

		virtual EMoveResult MakeMoveAt(int, int) = 0;

		static IGame::Ptr Produce();

		virtual ~IGame() = default;
	};

}
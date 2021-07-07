#pragma once
#include <iostream>

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
		Win,
		Draw
	};

	class IGame
	{
	public:
		using Ptr = std::shared_ptr<IGame>;
		 
		virtual void Configure(int, int) = 0;

		virtual void SetFirstPlayer(const std::string&) = 0;
		virtual void SetSecondPlayer(const std::string&) = 0;

		virtual int GetBoardSize() const = 0;
		virtual std::string GetCurrentPlayer() const = 0;
		virtual Piece GetPieceAt(int, int) const = 0;
		virtual GameState GetGameState() const = 0;

		virtual void MakeMoveAt(int, int) = 0;

		static IGame::Ptr Produce();

		virtual ~IGame() = default;
	};

}
#pragma once

#include <string>
#include <memory>
#include <vector>

namespace tictactoe
{
	enum class EPiece
	{
		None,
		X,
		O
	};

	enum class EGameState
	{
		None,
		Playing,
		XWon,
		OWon,
		Draw
	};

	enum class EGameType
	{
		SinglePlayer,
		TwoPlayers
	};

	enum class EMoveResult
	{
		Success = 0,
		PositionOccupied,
		InvalidCoordinates
	};

	enum class EStrategy
	{
		Easy,
		Medium
	};

	class IStrategy
	{
	public:
		virtual ~IStrategy() = default;

		virtual std::pair<int, int> GetMove(const std::vector<std::vector<EPiece>>&, int) = 0;
	};

	class IGame
	{
	public:
		using Ptr = std::shared_ptr<IGame>;

		virtual void Init(int, int, EGameType, bool computerFirst = false) = 0;

		virtual void SetFirstPlayer(const std::string&) = 0;
		virtual void SetSecondPlayer(const std::string&) = 0;
		virtual std::string GetFirstPlayer() const = 0;
		virtual std::string GetSecondPlayer() const = 0;

		virtual int GetBoardSize() const = 0;
		virtual std::string GetCurrentPlayer() const = 0;
		virtual EPiece GetPieceAt(int, int) const = 0;
		virtual EGameState GetGameState() const = 0;

		virtual void SetStrategy(EStrategy strategyType) = 0;
		virtual void SetStrategy(std::shared_ptr<IStrategy> newStrategy) = 0;

		virtual EMoveResult MakeMoveAt(int, int) = 0;

		static IGame::Ptr Produce();

		virtual ~IGame() = default;
	};

}
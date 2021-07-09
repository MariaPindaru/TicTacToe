#pragma once

#include <vector>

#include "API\GameAPI.h"

using namespace tictactoe;

class EasyStrategy : public IStrategy
{
public:
	std::pair<int, int> GetMove(const std::vector<std::vector<tictactoe::EPiece>>&, int) override;
};


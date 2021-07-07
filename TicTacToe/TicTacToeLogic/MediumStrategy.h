#pragma once

#include <vector>

#include ".\GameAPI.h"

using namespace tictactoe;

class MediumStrategy : public IStrategy
{
public:
	std::pair<int, int> GetMove(const std::vector<std::vector<tictactoe::Piece>>&) override;
};


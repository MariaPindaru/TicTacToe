#pragma once
#include <iostream>

class Player
{
public:
	Player();
	Player(std::string);
	void SetName(const std::string& name);
	std::string GetName() const;
	void SetIsMyTurn(bool opt);
	bool GetIsMyTurn() const;
	void ChangeTurn();

private:
	std::string m_name;
	bool m_isMyTurn;
};


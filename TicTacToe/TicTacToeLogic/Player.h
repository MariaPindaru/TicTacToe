#pragma once
#include <iostream>

class Player
{
public:
	Player();
	Player(std::string);
	void SetName(const std::string&);
	std::string GetName() const;
	void SetIsMyTurn(bool);
	bool GetIsMyTurn() const;
	void ChangeTurn();

private:
	std::string m_name;
	bool m_isMyTurn;
};


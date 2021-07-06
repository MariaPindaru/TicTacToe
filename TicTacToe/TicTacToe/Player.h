#pragma once
#include <iostream>

class Player
{
public:
	Player();
	Player(std::string);
	std::pair<int, int> SelectPosition(int dim);
	std::string GetName();
	bool operator==(Player);
private:
	std::string m_name;
};


#include "Player.h"

Player::Player()
{
}

Player::Player(std::string name) : m_name(name)
{
}

std::pair<int, int> Player::SelectPosition(int dim)
{
	std::pair<int, int> pos;
	std::cout << "Select position: ";
	std::cin >> pos.first >> pos.second;

	if (pos.first < 0 || pos.second < 0 || pos.first >= dim || pos.second >= dim)
		throw "Invalid position!";

	return pos;
}

std::string Player::GetName()
{
	return m_name;
}

bool Player::operator==(Player player)
{
	if (this->m_name == player.GetName())
		return true;
	return false;
}

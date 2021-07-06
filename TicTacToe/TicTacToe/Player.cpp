#include "Player.h"
#include <regex>

Player::Player()
{
}

Player::Player(std::string name) : m_name(name)
{
}

std::pair<int, int> Player::SelectPosition(int dim)
{
	std::string line, column;
	std::pair<int, int> pos;
	std::cout << "Select position: ";
	std::cin >> line >> column;

	if(!std::regex_match(line, std::regex("[0-9]+")) || !std::regex_match(line, std::regex("[0-9]+")))
		throw "Invalid input!";

	pos.first = std::stoi(line);
	pos.second = std::stoi(column);

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

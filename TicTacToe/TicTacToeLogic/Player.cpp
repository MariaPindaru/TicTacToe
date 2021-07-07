#include "Player.h"

Player::Player(): m_isMyTurn(false) {}

Player::Player(std::string name) : m_name(name), m_isMyTurn(false) {}

void Player::SetName(const std::string& name)
{
	m_name = name;
}

std::string Player::GetName() const
{
	return m_name;
}

void Player::SetIsMyTurn(bool opt)
{
	m_isMyTurn = opt;
}

bool Player::GetIsMyTurn() const
{
	return m_isMyTurn;
}

void Player::ChangeTurn()
{
	m_isMyTurn = !m_isMyTurn;
}

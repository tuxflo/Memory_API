#include "player.h"

Player::Player()
{
    _score = 0;
}

std::string Player::get_name()
{
    return _name;
}

int Player::get_score()
{
    return _score;
}

void Player::add_points(int points)
{
    _score += points;
}

void Player::set_name(std::string name)
{
    _name = name;
}

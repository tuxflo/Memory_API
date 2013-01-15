#include "./include/player.h"

Player::Player()
{
    _score = 0;
    _name = "Player";
}

Player::Player(const char* name)
{
    _name = name;
    _score = 0;
}

void Player::Player::set_name(const std::string &name)
{
    _name = name;
}

std::string Player::get_name()
{
    return _name;
}

void Player::add_points(int points)
{
    _score += points;
}

int Player::get_score()
{
    return _score;
}

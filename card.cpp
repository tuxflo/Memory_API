#include "card.h"

Card::Card()
{
    _turned = false;
    //Start value 100, for each "not right" turning subtracting 10 points
    _points = 100;
}

void Card::set_turned(bool b)
{
    _turned = b;
}

bool Card::get_turned()
{
    return _turned;
}

void Card::set_picture(std::string pic)
{
    _picture = pic;
}

std::string Card::get_picture()
{
    return _picture;
}

void Card::set_id(int id)
{
    _id = id;
}

int Card::get_id()
{
    return _id;
}

void Card::set_points(int p)
{
    if(_points > 0)
        _points -= p;
}

int Card::get_points()
{
    return _points;
}

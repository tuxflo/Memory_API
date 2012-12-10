#include "card.h"

Card::Card()
{
    _turned = false;
}

void Card::set_turned(bool b)
{
    _turned = b;
}

bool Card::get_turned()
{
    return _turned;
}

void Card::set_picture(int pic, int cover)
{
    _picture = pic;
    _cover = cover;
}

int Card::get_picture()
{
    return _picture;
}

int Card::get_cover()
{
    return _cover;
}

void Card::set_id(int id)
{
    _id = id;
}

int Card::get_id()
{
    return _id;
}

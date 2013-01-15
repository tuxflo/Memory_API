#include "./include/first_turn.h"
#include "./include/field_implementation.h"


First_Turn::First_Turn(Field_Implementation *field) : Memory_State(field)
{
}

void First_Turn::get_state()
{
    std::cout << "State: First turn" << std::endl;
}

void First_Turn::turn(int row, int column)
{
    _field->_first_card = &_field->_cards[row][column];
    _field->_first_card->set_turned(true);
    _field->_state = &_field->_second_turn;
}

#include "./include/second_turn.h"
#include "./include/field_implementation.h"

Second_Turn::Second_Turn(Field_Implementation *field) : Memory_State(field)
{
}

void Second_Turn::get_state()
{
    std::cout << "State: Second Turn!" << std::endl;
}

void Second_Turn::turn(int row, int column)
{
    //Turn the cards...
    _field->_second_card = &_field->_cards[row][column];
    _field->_second_card->set_turned(true);

    //Check if they match and so on...
    _field->_state = &_field->_end_turn;

    //Fake turn in the end round state
    _field->_state->turn(0,0);
    //Set state to first turn
    _field->_state = &_field->_first_turn;
}

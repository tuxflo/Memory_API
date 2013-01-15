#include "./include/end_turn.h"
#include "./include/field_implementation.h"
End_Turn::End_Turn(Field_Implementation *field) : Memory_State(field)
{
}

void End_Turn::get_state()
{
    std::cout << "State: End Turn!" << std::endl;
}

void End_Turn::turn(int row, int column)
{
    //std::cout << "Entered End_turn!" << std::endl;
    //Check if the cards match
    if(_field->match())
    {
        _field->_game_over = _field->check_game_over();
    }
    _field->end_round();
    _field->_state = & _field->_first_turn;
}

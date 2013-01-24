#ifndef SECOND_TURN_H
#define SECOND_TURN_H
#include "./include/memory_state.h"

class Second_Turn : public Memory_State
{
public:
    Second_Turn(Field_Implementation *Field_Implementation);
    void get_state();
    void turn(int row, int column);
};

#endif // SECOND_TURN_H

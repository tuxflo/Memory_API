#ifndef FIRST_TURN_H
#define FIRST_TURN_H

#include "memory_state.h"
class First_Turn : public Memory_State
{
public:
    First_Turn(Field_Implementation *field);
    void get_state();
    void turn(int row, int column);
private:
};

#endif // FIRST_TURN_H

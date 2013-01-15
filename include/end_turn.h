#ifndef END_TURN_H
#define END_TURN_H
#include "memory_state.h"

class End_Turn : public Memory_State
{
public:
    End_Turn(Field_Implementation *field);
    void get_state();
    void turn(int row, int column);
};

#endif // END_TURN_H

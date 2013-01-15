#ifndef MEMORY_STATE_H
#define MEMORY_STATE_H

#include <iostream>
class Field_Implementation;
class Memory_State
{
public:
    Memory_State(Field_Implementation *field) : _field(field){}
    virtual void get_state()=0;
    virtual void turn(int row, int column)=0;
protected:
    Field_Implementation *_field;
};

#endif // MEMORY_STATE_H

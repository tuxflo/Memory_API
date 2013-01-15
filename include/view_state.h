#ifndef VIEW_STATE_H
#define VIEW_STATE_H

class View_State
{
public:
    //View_State(View_State *field): _field(field){}
    virtual void turn(int row, int column)=0;
protected:
    //View_State *_field;
};

#endif // VIEW_STATE_H

#ifndef VIEW_STATE_H
#define VIEW_STATE_H

class View_State
{
public:
    virtual void turn(int row, int column)=0;
    virtual ~View_State(){}
protected:
};

#endif // VIEW_STATE_H

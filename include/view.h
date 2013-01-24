#ifndef VIEW_H
#define VIEW_H
#include "./include/view_state.h"
class View
{
public:
    View();
    virtual ~View(){}
    virtual void update()=0;
    virtual void turn(int row, int column)=0;
    virtual bool set_cards()=0;
    virtual void view_board()=0;
    virtual void play()=0;
    virtual void game_over()=0;
protected:
    View_State *_state;

};

#endif // VIEW_H

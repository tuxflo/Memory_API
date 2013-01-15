#ifndef GAME_INTERFACE_H
#define GAME_INTERFACE_H
#include <string>
#include <iostream>
#include <./include/view.h>

#include "./include/player.h"
#include "./include/memory_state.h"
#include "./include/first_turn.h"
#include "./include/second_turn.h"
#include "./include/end_turn.h"

class Game_Interface
{
public:
    //Initialisation
    virtual void set_picture_path(std::string picture_path)=0;
    virtual std::string get_picture_path(int row, int column)=0;

    virtual void set_cover_path(std::string cover_path)=0;
    virtual std::string get_cover_path()=0;
    virtual void add_player(const std::string& name)=0;
    virtual std::string get_actual_player_name()=0;
    virtual int get_actual_player_score()=0;
    void set_view(View *view);

    virtual int get_rows()=0;
    virtual int get_columns()=0;

    //Playing
    virtual bool turn(int row, int column)=0; //False if cant turn the card
    virtual bool get_turned(int row, int column)=0;
    virtual int match()=0;
    virtual void end_round()=0;
    virtual bool check_game_over()=0;
    virtual bool get_game_over()=0;
    virtual int get_recieved_points()=0;
    virtual ~Game_Interface(){}

    //Debugging
    void get_state();
protected:
    View *_view;
    //For Handeling the states
    Memory_State *_state;

};

#endif // GAME_INTERFACE_H

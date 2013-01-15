#ifndef FIELD_IMPLEMENTATION_H
#define FIELD_IMPLEMENTATION_H
#include <vector>
#include <stdlib.h>
#include <sstream>

#include "game_interface.h"
#include "memory_state.h"
#include "first_turn.h"
#include "second_turn.h"
#include "card.h"

class Field_Implementation : public Game_Interface
{
    friend class First_Turn;
    friend class Second_Turn;
    friend class End_Turn;
public:
    Field_Implementation(int rows, int columns);
    virtual ~Field_Implementation();

    //Initialisation
    void set_picture_path(std::string picture_path);
    std::string get_picture_path(int row, int column);

    void set_cover_path(std::string cover_path);
    std::string get_cover_path();
    void add_player(const std::string& name);

    int get_rows();

    int get_columns();

    //Playing
    bool turn(int row, int column);
    bool get_turned(int row, int column);
    void end_round();
    std::string get_actual_player_name();
    int get_actual_player_score();
    bool check_game_over();
    bool get_game_over();
    int match();
    int get_recieved_points();

private:
    int* _shuffle_array(int *array, int array_size);


    int _rows;
    int _columns;
    std::string _cover_path;
    Card **_cards;
    Card *_first_card;
    Card *_second_card;
    Player *_actual_player;
    std::vector<Player> *_players;

    //States
    First_Turn _first_turn;
    Second_Turn _second_turn;
    End_Turn _end_turn;
    bool _game_over;
    int _recieved_points;
};

#endif // FIELD_IMPLEMENTATION_H

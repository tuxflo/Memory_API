#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "card.h"
#include "player.h"
//Just for debugging (Setting cout to fixed size)
#include <iomanip>
#include <unistd.h>


class Board
{
public:
    Board(int rows, int columns);
    ~Board();
    void init_game(std::vector<Player> *p);

    void choose_card();
    void end_round();

    //For debugging
    void view_board();

 private:
    int _rows;
    int _columns;
    int _act_row;
    int _act_column;
    Card **_cards;
    Card *_actual_card;
    Card *_second_card;
    Card *_set_actual_card();


    std::vector<Player> *_players;
    Player *_actual_player;
    void _set_pictures();
    int* _shuffle_array(int *array, int array_size);

    int _turn();
    bool _set_actual_row(int row);
    bool _set_actual_column(int column);
};

#endif // BOARD_H

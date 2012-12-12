#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "card.h"
#include "player.h"
//Just for debugging (Setting cout to fixed size)
#include <iomanip>
#include <unistd.h>
#include <algorithm>


class Board
{
public:
    Board(int rows, int columns);
    ~Board();
    void init_game(std::vector<Player> *p);

    void choose_card();
    void end_round();

    void turn(int row, int column);

    //For debugging
    void view_board();

 private:
    int _rows;
    int _columns;    
    Card **_cards;
    Card *_actual_card;
    Card *_second_card;

    std::vector<Player> *_players;
    Player *_actual_player;
    void _set_pictures();
    int* _shuffle_array(int *array, int array_size);

    bool _match();
    bool _check_game_over();
};

#endif // BOARD_H

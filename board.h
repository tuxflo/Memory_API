#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sstream>
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
    void init_game(std::vector<Player> *p, std::string pictures, std::string cover);
    void end_round();
    void turn(int row, int column);

    std::string get_actual_player_name();
    int get_actual_player_score();

    bool get_turned(int row, int column);

    //Checks if the card was the last card

    bool check_game_over();

    //Returns true if a pair is found
    bool match();

    std::string get_picture(int row, int column);
    std::string get_cover();
    //For debugging
    void view_board();

 private:
    std::string _cover;
    int _rows;
    int _columns;    
    Card **_cards;
    Card *_actual_card;
    Card *_second_card;

    std::vector<Player> *_players;
    Player *_actual_player;
    void _set_pictures(std::string pictures, std::string cover);
    int* _shuffle_array(int *array, int array_size);

};

#endif // BOARD_H

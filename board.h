#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "card.h"
#include "player.h"

class Board
{
public:
    Board(int rows, int columns);
    ~Board();
    bool init_game();

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

    std::vector<Player> *players;
    Player *_actual_player;
    void _set_pictures();
    int* _shuffle_array(int *array, int array_size);

    int _turn();
    bool _set_actual_row(int row);
    bool _set_actual_column(int column);
};

#endif // BOARD_H

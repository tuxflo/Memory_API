#include <iostream>
#include "card.h"
#include "board.h"
#include "player.h"
using namespace std;

int main()
{
    Board board(3,4);
    vector<Player> players(2);
    players.at(0).set_name("tuxflo");
    players.at(1).set_name("anne");
    board.init_game(&players);

    board.turn(0, 0);
    board.turn(1, 1);

    return 0;
}


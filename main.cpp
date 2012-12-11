#include <iostream>
#include "card.h"
#include "board.h"
#include "player.h"
using namespace std;

int main()
{
    Board board(5,5);
    vector<Player> players(2);
    players.at(0).set_name_id("tuxflo", 0);
    players.at(1).set_name_id("anne", 0);
    board.init_game(&players);

    while(1)
    {
        board.choose_card();
    }

    return 0;
}


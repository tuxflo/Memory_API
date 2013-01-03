#include <iostream>
#include "card.h"
#include "board.h"
#include "player.h"
using namespace std;

int main()
{
    Board board(2,2);
    vector<Player> players(2);
    players.at(0).set_name("tuxflo");
    players.at(1).set_name("anne");
    board.init_game(&players, "/home/tuxflo/Pictures/", "cover");
    board.view_board();

    board.turn(0, 0);
    if(board.match())
        cout << "Geht doch gar nicht!";
    board.turn(1, 0);
    //Check if cards match and do something if they match
    if(!board.match())
    {
        //Cards do not match turn them back and select next player
        board.end_round();
    }
    //Card matches check if it was the last card
    else
        if(board.check_game_over())
        {
            //funny win animation here
            ;
        }
    return 0;
}


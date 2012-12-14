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

template <class T>
class Board
{
public:
    Board(int rows, int columns)
    {
        //Check number of cards
        if(rows*columns % 2 != 0)
        {
            std::cerr << "Error uneven number of cards!" << std::endl;
            exit(-1);
        }
        _rows = rows;
        _columns = columns;

        //Initialise the _card[][] array
        _cards = new Card<int>*[rows];
        for(int i=0; i<rows; i++)
            _cards[i] = new Card<int>[columns];

        _actual_card = 0;
        _second_card = 0;
    }

    ~Board()
    {
        for(int i=0; i<_rows; i++)
            delete [] _cards[i];
        delete[] _cards;
    }

    void init_game(std::vector<Player> *p)
    {
        _players = p;
        _actual_player = &_players->front();
        std::cout << "First Player: " << _actual_player->get_name() << std::endl;
        _set_pictures();
    }

    void end_round()
    {
        view_board();
        _actual_card->set_turned(false);
        _actual_card->set_points(10);
        _second_card->set_turned(false);
        _second_card->set_points(10);
        _actual_card = 0;
        _second_card = 0;
        //Find the next player and show the name
        if(_actual_player == &_players->at(_players->size()-1))
            _actual_player = &_players->front();
        else
        {
            for(unsigned int i=0; i<_players->size()-1; i++)
            {
                if(_actual_player == &_players->at(i))
                    _actual_player = &_players->at(i+1);
            }
        }
    }

    void turn(int row, int column)
    {
        if(row < 0 || row > _rows-1)
        {
            std::cerr << "Error: Row " << row << " not in grid!";
            exit(-1);
        }
        if(row < 0 || row > _columns-1)
        {
            std::cerr << "Error: Column " << column << " not in grid";
        }
        //First card
        if(_actual_card == 0)
        {
            _actual_card = &_cards[row][column];
            _actual_card->set_turned(true);

        }
        //Second card
        else
        {
            _second_card = &_cards[row][column];
            _second_card->set_turned(true);
        }
    }

    Player *get_actual_player()
    {
        return _actual_player;
    }

    //Checks if the card was the last card

    bool check_game_over()
    {
        int tmp = 0;
        for(int i=0; i<_rows; i++)
        {
            for(int j=0; j<_columns; j++)
            {
                if(_cards[i][j].get_turned())
                    tmp++;
            }
        }
        if(tmp == _rows*_columns)
        {
            return true;
        }
        else
            return false;
    }

    //Returns true if a pair is found
    bool match()
    {
        if(_actual_card->get_id() == _second_card->get_id())
        {
            std::cout << "Found right pair!" << std::endl;
            std::cout << "Player: " << _actual_player->get_name() << " gets " << _actual_card->get_points() + _second_card->get_points() << " points!" << std::endl;
            _actual_player->add_points(_actual_card->get_points()+_second_card->get_points());
            _actual_card = 0;
            _second_card = 0;
            return true;
        }
        return false;
    }

    //For debugging
    void view_board()
    {

        for(int i=0; i<_rows; i++)
        {
            for(int j=0; j<_columns; j++)
            {

                //Set output to fixed for better viewing the ids
                std::cout << std::setw(2);
                std::cout << std::setfill('0');
                if(_cards[i][j].get_turned())
                    std::cout <<  _cards[i][j].get_picture() << " ";
                else
                    std::cout << _cards[i][j].get_cover() << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        //Ultimate cheating :)
        for(int i=0; i<_rows; i++)
        {
            for(int j=0; j<_columns; j++)
            {    //Set output to fixed for better viewing the ids
                std::cout << std::setw(2);
                std::cout << std::setfill('0');
                    std::cout <<  _cards[i][j].get_picture() << " ";
            }
            std::cout << std::endl;
        }
    }

 private:
    int _rows;
    int _columns;    
    Card<T> **_cards;
    Card<T> *_actual_card;
    Card<T> *_second_card;

    std::vector<Player> *_players;
    Player *_actual_player;
    void _set_pictures()
    {
        int count = _rows * _columns;

        //Set the Id of the cards in the right order (from 1-count/2)
        int *picture_ids = new int [count];
        int tmp = 1;
        for(int i=0; i<count; i++)
        {
            if(tmp > count/2)
                tmp = 1;
            picture_ids[i] = tmp;
            tmp++;
        }

        //Shuffle the array for randomly placing the pictures
        //picture_ids = _shuffle_array(picture_ids, count);

        //Add the pictures to the board
        int size=0; //Counter for converting the array picture_ids to the 2d array
        for(int i=0; i<_rows; i++)
        {
            for(int j=0; j<_columns; j++)
            {
                _cards[i][j].set_picture(picture_ids[size], 0);
                _cards[i][j].set_id(picture_ids[size]);
                size++;
            }
        }
        delete [] picture_ids;
    }
    int* _shuffle_array(int *array, int array_size)
    {
        //Set time for randomizing
        srand((unsigned)time(0));

        for(int i=0;i<array_size-1; i++)
        {
            int c = i +(rand() % (array_size-i));
            //Swap values
            int tmp = array[i];
            array[i] = array[c];
            array[c] = tmp;
        }
        return array;
    }

};

#endif // BOARD_H

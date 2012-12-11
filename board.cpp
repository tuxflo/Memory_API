#include "board.h"

Board::Board(int rows, int columns)
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
    _cards = new Card*[rows];
//    if(rows > columns)
//    {
//        for(int i=0; i<columns+(rows-columns); i++)
//            _cards[i] = new Card[columns];
//    }
    for(int i=0; i<rows; i++)
        _cards[i] = new Card[columns];

    _actual_card = 0;
    _second_card = 0;
}

Board::~Board()
{
    for(int i=0; i<_rows; i++)
        delete [] _cards[i];
    delete[] _cards;
}

void Board::init_game(std::vector<Player> *p)
{
    _players = p;
    _actual_player = &_players->front();
    std::cout << "First Player: " << _actual_player->get_name() << std::endl;
    _set_pictures();
}

void Board::choose_card()
{
    int r;
    int c;
    std::cout << "Please select row: ";
    std::cin >> r;
    if(!_set_actual_row(r))
        return choose_card();
    std::cout << "Please select column: ";
    std::cin >> c;
    if(!_set_actual_column(c))
        return choose_card();
    if(_cards[r][c].get_turned())
    {
        std::cout << "Error: card[" << r << "]" << "[" << c << "] is already turned. Please select a different card" << std::endl;
        return choose_card();
    }
    _turn();
}

void Board::end_round()
{

    if(_actual_card->get_id() == _second_card->get_id())
    {
        std::cout << "Found right pair!" << std::endl;
        std::cout << "Player: " << _actual_player->get_name() << " gets " << _actual_card->get_points() + _second_card->get_points() << " points!" << std::endl;
        _actual_player->add_points(_actual_card->get_points()+_second_card->get_points());
        if(_check_game_over())
            exit(0);

        _actual_card = 0;
        _second_card = 0;

    }
    else
    {
        _actual_card->set_turned(false);
        _actual_card->set_points(10);
        _second_card->set_turned(false);
        _second_card->set_points(10);
        _actual_card = 0;
        _second_card = 0;
    }
    sleep(2);
    view_board();
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
    std::cout << "Now its your turn " << _actual_player->get_name()  << " Actual score: " << _actual_player->get_score() << std::endl;
}

void Board::view_board()
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

void Board::_set_pictures()
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
    picture_ids = _shuffle_array(picture_ids, count);

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
    view_board();
}

int* Board::_shuffle_array(int *array, int array_size)
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

void Board::_turn()
{
    //First card
    if(_actual_card == 0)
    {
        _actual_card = _set_actual_card();
        _actual_card->set_turned(true);

        //Just for debugging
        view_board();
    }
    //Second card
    else
    {
        _second_card = _set_actual_card();
        _second_card->set_turned(true);
       //Just for debugging
        view_board();

        end_round();
    }
}

Card* Board::_set_actual_card()
{
    return &_cards[_act_row][_act_column];
}

bool Board::_set_actual_row(int row)
{
    if(row < 0 || row > _rows-1)
    {
        std::cout << "Error: cannot set row to " << row << std::endl;
        return false;
    }
    _act_row = row;
    return true;
}

bool Board::_set_actual_column(int column)
{
    if(column < 0 || column >_columns-1)
    {
        std::cout << "Error cannot set column to " << column << std::endl;
        return false;
    }
    _act_column = column;
    return true;
}

bool Board::_check_game_over()
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
        std::cout << "Game over!" << std::endl;
        int max_points = _actual_player->get_score();
        for(unsigned int i=0; i<_players->size()-1; i++)
        {
            if(_players->at(i).get_score() > max_points)
            {
                _actual_player = &_players->at(i);
                max_points = _actual_player->get_score();
            }
        }

        //Not the best solution but so I can check if more than one player wins
        for(unsigned int i=0; i<_players->size(); i++)
        {
            if(_players->at(i).get_score() == max_points)
                std::cout << "Player: " << _players->at(i).get_name() << " wins with" << _players->at(i).get_score() << " points!" << std::endl;
        }

        return true;
    }
    else
        return false;
}

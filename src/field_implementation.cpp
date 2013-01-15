#include "./include/field_implementation.h"

Field_Implementation::Field_Implementation(int rows, int columns) :
    _first_turn(this), _second_turn(this), _end_turn(this)
{
    _players = new std::vector<Player>;
    _actual_player = 0;
    //Check number of cards
    if(rows*columns % 2 != 0)
    {
        std::cerr << "Error: uneven number of cards!" << std::endl;
        exit(-1);
    }
    _rows = rows;
    _columns = columns;

    //Initialise the _card[][] array
    _cards = new Card*[rows];
    for(int i=0; i<rows; i++)
        _cards[i] = new Card[columns];

    _first_card = 0;
    _second_card = 0;

    _state = &_first_turn;
    _game_over = false;
    _recieved_points = 0;
}

Field_Implementation::~Field_Implementation()
{
    for(int i=0; i<_rows; i++)
        delete [] _cards[i];
    delete[] _cards;
}

bool Field_Implementation::turn(int row, int column)
{
    if(row < 0 || row > _rows-1)
        return false;
    if(row < 0 || row > _columns-1)
        return false;

    _state->turn(row, column);
    //_view->update();
    return true;
}

bool Field_Implementation::get_turned(int row, int column)
{
    return _cards[row][column].get_turned();
}

int Field_Implementation::match()
{
    if(_first_card->get_id() == _second_card->get_id())
    {
        //ID's are the same so the cards match!

        _recieved_points = _first_card->get_points() + _second_card->get_points();
        _actual_player->add_points(_recieved_points);
        _first_card = 0;
        _second_card = 0;
        return _recieved_points;
    }
    //The cards don't match
    _recieved_points = 0;
    _first_card->set_turned(false);
    _first_card->set_points(10);
    _first_card = 0;

    _second_card->set_turned(false);
    _second_card->set_points(10);
    _second_card = 0;
    return 0;
}

int Field_Implementation::get_recieved_points()
{
    return _recieved_points;
}

void Field_Implementation::end_round()
{
    //Find the next player and set him/her active

        for(unsigned int i=0; i<_players->size()-1; i++)
        {
            if(_actual_player == &_players->at(i))
                _actual_player = &_players->at(i+1);
            else
                _actual_player = &_players->front();
        }
    _view->update();
}

void Field_Implementation::set_picture_path(std::string picture_path)
{
    int count = _rows * _columns;

    //Set the cover (the same for all cards)
    //_cover = cover;

    std::stringstream directory_name;

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
            //The Picture is the directory name + the card name like /pictures/1
            directory_name << picture_path << picture_ids[size];
            _cards[i][j].set_picture_path(directory_name.str());
            _cards[i][j].set_id(picture_ids[size]);
            size++;
            directory_name.str("");
        }
    }
    delete [] picture_ids;
}

std::string Field_Implementation::get_picture_path(int row, int column)
{
    return _cards[row][column].get_picture_path();
}

void Field_Implementation::set_cover_path(std::string cover_path)
{
    _cover_path = cover_path;
}

std::string Field_Implementation::get_cover_path()
{
    return _cover_path;
}

void Field_Implementation::add_player(const std::string &name)
{
    _players->push_back(Player(name.c_str()));
    //Set the first player as active player
    //if(_actual_player == 0)
        _actual_player = &_players->front();
}

int Field_Implementation::get_rows()
{
    return _rows;
}

int Field_Implementation::get_columns()
{
    return _columns;
}

std::string Field_Implementation::get_actual_player_name()
{
    return _actual_player->get_name();
}

int Field_Implementation::get_actual_player_score()
{
    return _actual_player->get_score();
}

bool Field_Implementation::check_game_over()
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

bool Field_Implementation::get_game_over()
{
    return _game_over;
}

int *Field_Implementation::_shuffle_array(int *array, int array_size)
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

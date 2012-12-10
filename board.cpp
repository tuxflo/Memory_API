#include "board.h"

Board::Board(int rows, int columns)
{
    _rows = rows;
    _columns = columns;
    _cards = new Card*[rows];
    for(int i=0; i<columns; i++)
        _cards[i] = new Card[columns];
}

Board::~Board()
{
    for(int i=0; i<_rows; i++)
        delete [] _cards[i];
    delete[] _cards;
}

bool Board::init_game()
{
}

void Board::choose_card()
{

}

void Board::end_round()
{


}

void Board::view_board()
{

}

void Board::_set_pictures()
{

}

int* Board::_shuffle_array(int *array, int array_size)
{

}

int Board::_turn()
{

}

Card* Board::_set_actual_card()
{

}

bool Board::_set_actual_row(int row)
{

}

bool Board::_set_actual_column(int column)
{

}

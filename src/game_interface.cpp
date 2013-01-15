#include "./include/game_interface.h"

void Game_Interface::set_view(View *view)
{
    _view = view;
}

void Game_Interface::get_state()
{
    _state->get_state();
}


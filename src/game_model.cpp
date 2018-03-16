#include "../include/game_model.h"

std::string Game::get_game_UUID()
{
  return _game_UUID;
}

std::string Game::get_dealer_UUID()
{
  return _dealer_UUID;
}

game_state Game::get_gstate()
{
  return _gstate;
}

Player_State Game::get_active_player()
{
  return _players[_active_player];
}

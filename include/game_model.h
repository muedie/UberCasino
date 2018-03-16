#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include "../include/player_state_model.h"
#include <string>

enum game_state {waiting_to_join, waiting, playing};

class Game
{
  public:
    std::string get_game_UUID();
    std::string get_dealer_UUID();
    game_state get_gstate();
    Player_State get_active_player();

  private:
    std::string _game_UUID;
    std::string _dealer_UUID;
    std::vector<Player_State> _players;
    game_state _gstate;
    int _active_player;
};

#endif

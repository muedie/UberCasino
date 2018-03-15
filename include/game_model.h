#ifndef GAME_MODEL_H
#define GAME_MODEL_H
#include "../include/player_state_model.h"
#include <string>

enum game_state {waiting_to_join, waiting, playing};

class Game
{
public:

private:
  std::string game_UID;
  std::string dealer_UID;
  std::vector<Player_State> players;
  game_state gstate;
};

#endif

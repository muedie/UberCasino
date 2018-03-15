#ifndef PLAYER_STATE_MODEL_H
#define PLAYER_STATE_MODEL_H
#include <vector>
#include "../include/card_model.h"
#include <string>

class Player_State
{
public:
  bool check_bust();
  bool check_blackjack();
  bool can_split();
private:
  std::string UUID;
  std::vector<Card> cards;
  std::vector<int> running_totals;
};

#endif

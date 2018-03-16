#ifndef PLAYER_STATE_MODEL_H
#define PLAYER_STATE_MODEL_H
#include <vector>
#include "../include/card_model.h"
<<<<<<< HEAD:include/hand_model.h
=======
#include <string>
>>>>>>> 4115a2316df5212d0e65bcda86c6c26b5117ec32:include/player_state_model.h

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

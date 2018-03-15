#ifndef HAND_MODEL_H
#define HAND_MODEL_H
#include <vector>
#include "card.h"

class Hand{
public:
  bool check_bust();
  bool check_blackjack();
  bool can_split();
private:
  std::vector<Card> cards;
  std::vector<int> running_totals;
};

#endif

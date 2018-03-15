#include "../include/player_state_model.h"

bool Player_State::check_bust()
{
  for(int i=0; i<running_totals.size(); i++)
  {
    if(running_totals[i] > 21)
      return true;
  }

  return false;
}

bool Player_State::check_blackjack()
{
  for(int i=0; i<running_totals.size(); i++)
  {
    if(running_totals[i] == 21)
      return true;
  }

  return false;
}

bool Player_State::can_split()
{
  if((cards.size() == 2) && (cards[0].get_value() == cards[1].get_value()))
    return true;

  return false;
}

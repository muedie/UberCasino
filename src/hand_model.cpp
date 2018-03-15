#include "hand_model.h"

bool Hand::check_bust()
{
  for(int i=0; i<running_totals.size(); i++)
  {
    if(running_totals[i] > 21)
      return true;
  }

  return false;
}

bool Hand::check_blackjack()
{
  for(int i=0; i<running_totals.size(); i++)
  {
    if(running_totals[i] == 21)
      return true;
  }

  return false;
}

bool Hand::can_split()
{
  if((cards.size() == 2) && (cards[0].get_value() == cards[1].get_value()))
    return true;

  return false;
}

#include <card.h>

using namespace std;

Card::Card(){}

int Card::get_value()
{
  return _value;
}

void Card::set_face(bool face)
{
  _faced_up = face;
}

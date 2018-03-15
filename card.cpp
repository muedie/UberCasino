#include <card.h>

using namespace std;

Card::Card():{}

int Card::get_value()
{
  return _value;
}

void Card::set_face(bool face)
{
  faced_up = face;
}

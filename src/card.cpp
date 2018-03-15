#include "card.h"

Card::Card(long value, suite_t suite)
{
  _value = value;
  _suite = suite;
}

long Card::get_value()
{
  return _value;
}

void Card::set_face(bool face)
{
  _faced_up = face;
}

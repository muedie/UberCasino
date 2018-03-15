#ifndef CARD_H
#define CARD_H

enum suite_t {hearts, diamonds, clubs, spades};

class Card
{
  public:
    Card(long value, suite_t suite);
    long get_value();
    void set_face(bool faced_up);
  private:
    long _value;
    suite_t _suite;
    bool _faced_up;

};

#endif

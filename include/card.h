#ifndef CARD_H
#define CARD_H

using namespace std;

class Card
{
  public:
    Card();
    int get_value();
    void set_face(bool faced_up);
  private:
    long _value;
    int _suit;
    bool _faced_up;

};

#endif

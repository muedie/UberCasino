#include "../ccpp_UberCasino.h"
#include "player.h"



// PTR is a global.  Horrible hack
extern player* PTR;

void _cb ( UberCasino::Player P )
{

  PTR->external_data ( P );
}
void _cb ( UberCasino::Dealer D )
{

  PTR->external_data ( D );
}
void _cb ( UberCasino::Game G )
{

  PTR->external_data ( G );
}

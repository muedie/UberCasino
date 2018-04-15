#include "../ccpp_UberCasino.h"
#include "player.h"

// PTR is a global.  Horrible hack
extern player* PTR;

std::string to_string ( UberCasino::player_action_t t )
{
   std::string retval;
   switch ( t )
   {
      case idle:retval="idle";break;
      case hitting:retval="hitting";break;
      case standing:retval="standing";break;
      case splitting:retval="splitting";break;
      case doubling:retval="doubling";break;
   }
   return retval;
}

std::string to_string ( UberCasino::game_state t )
{
   std::string retval;
   switch ( t )
   {
      case waiting_to_join:retval = "waiting_to_joing";break;
      case waiting:retval = "waiting";break;
      case playing:retval = "playing";break;
      case end_hand:retval = "end_hand";break;
   }
   return retval;
}

std::string to_string ( UberCasino::suite_t t )
{
   std::string retval;
   switch ( t )
   {
     case hearts:retval = "hearts";break;
     case diamonds:retval = "diamonds";break;
     case clubs:retval = "clubs";break;
     case spades:retval = "spades";break;
   }
   return retval;
}

std::string to_string ( UberCasino::card_kind t )
{
   std::string retval;
   switch ( t )
   {
      case ace:retval = "ace";break;
      case two:retval = "two";break;
      case three:retval = "three";break;
      case four:retval = "four";break;
      case five:retval = "five";break;
      case six:retval = "six";break;
      case seven:retval = "seven";break;
      case eight:retval = "eight";break;
      case nine:retval = "nine";break;
      case ten:retval = "ten";break;
      case jack:retval = "jack";break;
      case queen:retval = "queen";break;
      case king:retval = "king";break;
   }
   return retval;
}

void _cb ( UberCasino::Player P )
{
  std::cout << "\nPlayer Received!\n";

  PTR->external_data ( P );
}
void _cb ( UberCasino::Dealer D )
{
    std::cout << "\nDealer Received!\n";

  PTR->external_data ( D );
}
void _cb ( UberCasino::Game G )
{

    std::cout << "Game: " << to_string ( G.gstate ) << " idx = " << G.active_player << std::endl;
      std::cout << "RECEIVED -- Game" << std::endl;
      std::cout << "         gstate " << to_string ( G.gstate ) << std::endl;
      boost::uuids::uuid u;
      memcpy(&u, G.game_uid, 16);
      std::cout << "     game   uid " << boost::uuids::to_string( u ) << std::endl;
      std::cout << "  active player " << G.active_player << std::endl;
      memcpy(&u, G.p[G.active_player].uid, 16);
      std::cout << "    player uuid " << boost::uuids::to_string( u ) << std::endl;
      for (unsigned int i=0;i<UberCasino::MAX_CARDS_PER_PLAYER;i++)
      {
         if ( G.p[G.active_player].cards[i].valid )
         {
            std::cout  << "      " << to_string ( G.p[G.active_player].cards[i].card  )
                       << "      " << to_string ( G.p[G.active_player].cards[i].suite )
                      << std::endl;
         }
      }
      std::cout << "    The Dealers Cards:" << std::endl;
      for (unsigned int i=0;i<UberCasino::MAX_CARDS_PER_PLAYER;i++)
      {
         if ( G.dealer_cards[i].valid )
         {
            std::cout  << "      " << to_string ( G.dealer_cards[i].card  )
                       << "      " << to_string ( G.dealer_cards[i].suite )
                      << std::endl;
         }
      }

      std::cout << "-------------------------------------------------------"
                << std::endl;

  PTR->external_data ( G );
}

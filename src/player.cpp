#include <iostream>
#include <functional>
#include <cstdlib>
#include <boost/uuid/uuid.hpp>

#include <boost/uuid/uuid_io.hpp>


#include <boost/thread.hpp>

//timer thread for countdown
#define TIMER(SECS) \
    if ( m_timer_thread )\
    {\
       m_timer_thread->interrupt ();\
       delete ( m_timer_thread );\
       m_timer_thread = NULL;\
    }\
    m_timer_thread = new boost::thread ( delay_thread , SECS , std::bind ( &player::timer_expired , this ) );\



#include "player.h"

unsigned int Hand_Value ( UberCasino::card_t cards[] )
{
   // given an array of cards, returns the point value
   // this routine is ignorant of the different values
   // for an ace, it is always 1.

   unsigned int total=0;
   for (unsigned int i=0; i< UberCasino::MAX_CARDS_PER_PLAYER;i++)
   {
      if ( cards[i].valid )
      {
         switch ( cards[i].card )
         {
            case ace: total=total+1;break;
            case two: total=total+2;break;
            case three: total=total+3;break;
            case four: total=total+4;break;
            case five: total=total+5;break;
            case six: total=total+6;break;
            case seven: total=total+7;break;
            case eight: total=total+8;break;
            case nine: total=total+9;break;
            case ten: total=total+10;break;
            case jack: total=total+10;break;
            case queen: total=total+10;break;
            case king: total=total+10;break;
         }
      }
   }
   return total;
}

int card_value (UberCasino::card_t card) {
  if (card.valid) {
    switch (card.card) {
      case ace: return 1;
      case two: return 2;
      case three: return 3;
      case four: return 4;
      case five: return 5;
      case six: return 6;
      case seven: return 7;
      case eight: return 8;
      case nine: return 9;
      case ten:
      case jack:
      case queen:
      case king: return 10;
    }
  }
  return 0;
}

void delay_thread ( int seconds, std::function <void(void)> callback)
{
  callback ();
}

void player::lock ()
{
  // if this code is being used as part of an fltk program
  // a lock may be needed.  The fltk lock or something
  // like pthread_mutex() should work fine.
  std::cout << "****************************************" << std::endl;
}

void player::unlock ()
{
  // see comments under the lock () method
}

std::string player::to_string ( player_state_t p )
{
   // turn the player_state enumerant into a string
   std::string retval;
   switch ( p )
   {
      case Init:
         retval = "Init";
         break;
      case StartHand:
         retval = "StartHand";
         break;
      case Playing:
         retval = "Playing";
         break;
      case EndHand:
         retval = "EndHand";
         break;
   }
   return retval;
}


void player::manage_state ()
{
   bool transition = false;
   player_state_t next_state = m_player_state;
   //std::cout << "\n1: m_player_state: " << to_string(m_player_state);
   switch ( m_player_state )
   {
     case Init:
         {
            //std::cout << "\nEntered init state: m_Dealer_recv: " << m_Dealer_recv;
            // a dealer is starting a game
            if ( m_Dealer_recv )
            {
                std::cout << "\nm_Dealer_recv was true\n";
                transition = true;
            }
            // the player has entered a string

            std::cout << "\nm_user_event: " << m_user_event;

            if ( m_user_event && strcmp(m_user_event_string.c_str(), "bet") == 0 )      //only when bet button is clicked
            {
                  transition = true;
                  next_state = StartHand;
            }
         }
         break;
     case StartHand:
         {
             if ( m_Game_recv_idx )
             {
                 transition = true;
                 next_state = Playing;
             }
         }
         break;
     case Playing:
         {
             if ( m_Game_recv )
             {
                 // the dealers cards are dealt
                 transition = true;
                 next_state = EndHand;
             }
             if ( m_Game_recv_idx || m_user_event )
             {
                 transition = true;
                 next_state = Playing;
             }
         }
         break;
     case EndHand:
         {

         }
         break;
   }

   if ( m_player_state != next_state )
   {
      std::cout << "State change from " << to_string (m_player_state)
                << " to " << to_string ( next_state ) << std::endl;
   }
   // if there is a transition, then we have to run the exit
   // and entrance processing
   if (transition)
   {
      // on exit
      std::cout << "\nTransition (True): m_player_state: " << to_string(m_player_state) << std::endl;
      switch (m_player_state)
      {
         case Init:
         {
//#ifdef DEBUG_STATES
           std::cout << "Init: Exit" << std::endl;
//#endif
           // Wait 30 seconds for the dealer to act
           // if he does not act, then he has not accepted us into the game
           m_timer_event    = 30;
           TIMER(30);
         }
         break;
         case StartHand:
         {
//#ifdef DEBUG_STATES
           std::cout << "StartHand Exit" << std::endl;
//#endif
         }
         break;
         case Playing:
         {
#ifdef DEBUG_STATES
           std::cout << "Playing: Exit" << std::endl;
#endif
         }
         break;
         case EndHand:
         {
#ifdef DEBUG_STATES
           std::cout << "EndHand: Exit" << std::endl;
#endif
         }
         break;
      }

      // on entrance
      std::cout << "\nnext_state: " << to_string(next_state);

      switch (next_state)
      {
         case Init:
         {
#ifdef DEBUG_STATES
            std::cout << "Init: Entry" << std::endl;
#endif
            if (m_Dealer_recv)
            {
               m_dealer_list.push_back ( m_D );
           }
            // print the list to stdout
            if (m_dealer_list.size () > 0 )
            {
              for (unsigned int i=0;i<m_dealer_list.size ();i++)
              {
                 std::cout << "Dealer # " << i
                           << " name " << m_dealer_list[i].name << std::endl;
              }
              std::cout << "Enter the Dealer # to join.." << std::endl;
            }
         }
         break;
         case StartHand:
         {
//#ifdef DEBUG_STATES
               std::cout << "Waiting: StartHand" << std::endl;
//#endif
               memcpy ( m_P.game_uid,
                        m_dealer_list[m_dealer_idx].game_uid,
                        sizeof ( m_P.game_uid ) );
               m_P.A = idle;
               // put the game_uuid in a member var a little
               // easier to find
               memcpy ( &m_current_game_uuid,
                        m_dealer_list[m_dealer_idx].game_uid,
                        sizeof ( m_P.game_uid ) );
               p_io->publish  ( m_P );
         }
         break;
         case Playing:
         {
#ifdef DEBUG_STATES
            std::cout << "Playing: Entry " << std::endl;
#endif
            d_value = Hand_Value ( m_G.dealer_cards );
            value = Hand_Value ( m_G.p[m_G.active_player].cards );
            std::cout << "The value of my hand is "<< value << std::endl;
            std::cout << "State " << to_string ( next_state ) << std::endl;

              //Strategy Suggestion

            switch(play_style)
            {
              case 1:     //no strategy for manual
              break;
              case 2: {
                  //implement for basic strategy here
                  int d_upcard = card_value(m_G.dealer_cards[0]);

                  // on value basis
                  if (value >= 5 && value <= 8) {
                    suggest = "Hit";
                  } else if (value == 9) {
                    if (d_upcard >= 3 && d_upcard <= 6) {
                      suggest = "Double Down";
                    } else suggest = "Hit";
                  } else if (value == 10) {
                    if (d_upcard >= 2 && d_upcard <= 9) {
                      suggest = "Double Down";
                    } else if (d_upcard == 1 || d_upcard == 10) {
                      suggest = "Hit";
                    }
                  } else if (value == 11) {
                    if (d_upcard >= 2 && d_upcard <= 10) {
                      suggest = "Double Down";
                    } else if (d_upcard == 1) {
                      suggest = "Hit";
                    }
                  } else if (value == 12) {
                    if (d_upcard >= 4 && d_upcard <= 6) {
                      suggest = "Stand";
                    } else {
                      suggest = "Hit";
                    }
                  } else if (value >= 13 && value <= 16) {
                    if (d_upcard >= 2 && d_upcard <= 6) {
                      suggest = "Stand";
                    } else {
                      suggest = "Hit";
                    }
                  } else if (value == 17 || value == 18) {
                    suggest = "Stand";
                  }

                  // on card basis
                  int my_card1 = card_value(m_G.p[m_G.active_player].cards[0]);
                  int my_card2 = card_value(m_G.p[m_G.active_player].cards[1]);

                  if (my_card1 == 1) {
                    switch(my_card2) {
                      case 2:
                      case 3: {
                        if (d_upcard == 5 || d_upcard == 6) {
                          suggest = "Double Down";
                        } else suggest = "Hit";
                      } break;
                      case 4:
                      case 5: {
                        if (d_upcard >= 4 &&  d_upcard <= 6) {
                          suggest = "Double Down";
                        } else suggest = "Hit";
                      } break;
                      case 6: {
                        if (d_upcard >= 3 &&  d_upcard <= 6) {
                          suggest = "Double Down";
                        } else suggest = "Hit";
                      } break;
                      case 7: {
                        if (d_upcard >= 3 &&  d_upcard <= 6) {
                          suggest = "Double Down";
                        } else if (d_upcard == 2 || d_upcard == 7 || d_upcard == 8) {
                          suggest = "Stand";
                        } else if (d_upcard == 9 || d_upcard == 10 || d_upcard == 1) {
                          suggest = "Hit";
                        }
                      } break;
                      case 8:
                      case 9:
                      case 10: {
                        suggest = "Stand";
                      } break;
                      case 1: {
                        suggest = "Split";
                      }
                    }
                  } else if (my_card1 == 2 && my_card2 == 2) {
                    if (d_upcard >= 2 && d_upcard <= 7) {
                      suggest = "Split";
                    } else suggest = "Hit";
                  } else if (my_card1 == 3 && my_card2 == 3) {
                    if (d_upcard >= 2 && d_upcard <= 7) {
                      suggest = "Split";
                    } else suggest = "Hit";
                  } else if (my_card1 == 4 && my_card2 == 4) {
                    if (d_upcard == 5 || d_upcard == 6) {
                      suggest = "Split";
                    } else suggest = "Hit";
                  } else if (my_card1 == 5 && my_card2 == 5) {
                    suggest = "Don't Split";
                  } else if (my_card1 == 6 && my_card2 == 6) {
                    if (d_upcard >= 2 && d_upcard <= 6) {
                      suggest = "Split";
                    } else suggest = "Hit";
                  } else if (my_card1 == 7 && my_card2 == 7) {
                    if (d_upcard >= 2 && d_upcard <= 7) {
                      suggest = "Split";
                    } else suggest = "Hit";
                  } else if (my_card1 == 8 && my_card2 == 8) {
                    suggest = "Split";
                  } else if (my_card1 == 9 && my_card2 == 9) {
                    if ((d_upcard >= 2 && d_upcard <= 6) || d_upcard == 8 || d_upcard == 9) {
                      suggest = "Split";
                    } else if (d_upcard == 7 || d_upcard == 10 || d_upcard == 1) {
                      suggest = "Stand";
                    }
                  } else if (my_card1 == 10 && my_card2 == 10) {
                    suggest = "Stand";
                  }

                  // if cases don't catch situation
                  if (strcmp(suggest.c_str(), "") == 0) {
                    suggest = "Error!";
                  }


                }
              break;
              case 3:
                    if (value <17) suggest = "Hit";
                    else suggest = "Stand";
              break;
              case 4: {
                // counting
                int count_total = 0;

                for (int i = 0; i < UberCasino::MAX_PLAYERS_IN_A_GAME; i++) {
                  // every player
                  for (int j = 0; j < UberCasino::MAX_CARDS_PER_PLAYER; j++) {
                    //every card
                    if (m_G.p[i].cards[j].valid) {
                      int c_value = card_value(m_G.p[i].cards[j]);
                      if (c_value >=2 && c_value <=6)
                        count_total++;
                      else if (c_value == 10)
                        count_total--;
                    }
                  }
                }

                if (count_total > 0)
                  suggest = "Hit";
                else
                  suggest = "Stand";

              }
              break;
              case 5:
                    if (value <12) suggest = "Hit";
                    else suggest = "Stand";
              break;

            }


            if (strcmp(m_user_event_string.c_str(), "hit") == 0) {      //when hit button is clicked
                std::cout << "\nHIT: m_user_event: " << m_user_event_string << "Next state: " << next_state;
                m_P.A = hitting;
                p_io->publish  ( m_P );
            } else if (strcmp(m_user_event_string.c_str(), "stand") == 0) {       //when stand button is clicked
                std::cout << "\nSTAND: m_user_event: " << m_user_event_string << "Next state: " << next_state;
                m_P.A = standing;
                boost::this_thread::sleep_for(boost::chrono::seconds(1));     //delay for practical use
                p_io->publish  ( m_P );         //player sends player action to dealer
            }
            else if (strcmp(m_user_event_string.c_str(), "dd") == 0) {        //when double down button is clicked
                std::cout << "\nDouble Down: m_user_event: " << m_user_event_string << "Next state: " << next_state;
                m_P.A = hitting;
                d_down = true;
                p_io->publish  ( m_P );
                m_balance = m_balance - bet_amt;
                bet_amt = 2*bet_amt;        //bet amount increases by 2
            }
         }
         break;
         case EndHand:
         {
#ifdef DEBUG_STATES
            std::cout << "EndHand: Entry " << std::endl;
#endif
            if  ( m_G.gstate == end_hand )
            {
              std::cout << "The dealer says end of hand." << std::endl;
              // calculate win or lose
              d_value = Hand_Value ( m_G.dealer_cards );
              value = Hand_Value ( m_G.p[m_G.active_player].cards );
              std::cout << "Dealer has " << d_value << " Player has " << value << std::endl;
              if ( d_value > 21 || ( (value > d_value) && (value <= 21) ) )       //check if the player is winning or dealer
              {
                 std::cout << "Player Wins" << std::endl;
                 if(value == 21)
                 {
                   win = 4;
                   m_balance = m_balance + (2.5*bet_amt); //BlackJack.. 3:2 payout
                 }
                 else
                 {
                  m_balance = m_balance + (2.0*bet_amt);      //regulay payout
                 }
                 hands_won++;
                 hands_played++;
                 win = 1;
              }
              else if (value == d_value)          //if both has same value, game is pushed PUSH
              {
                std::cout << "PUSH" << std::endl;
                hands_played++;
                m_balance = m_balance + bet_amt;      //bet returned
                win = 0;
              }
              else
              {
                 std::cout << "Dealer Wins" << std::endl;
                 hands_played++;
                 win = 2;
              }
              m_timer_event    = 15;
              TIMER(15);        //15 second countdown for player response

              if (m_balance > 10.0 )        //checks if the player balance is low
              {
                 boost::this_thread::sleep_for(boost::chrono::seconds(2));
                 next_state = Init;
                 start = true;
              }
              else
              {
                 std::cout << "Down to " << m_balance << " exiting from game " << std::endl;
                 exit(0);
                 start = false;
              }
            }

         }
         break;
      }

      // make the transition
      m_player_state = next_state;
   }

   // clear all event flags
   m_user_event_string = "";
   m_user_event    = false;
   m_Player_recv   = false;
   m_Game_recv_idx = false;
   m_Game_recv     = false;
   m_Dealer_recv   = false;

}

void player::timer_expired ( )        //decrease time by 1 second each second.. countdown implementation
{
  while(m_timer_event != 0)
  {
    boost::this_thread::sleep_for(boost::chrono::seconds(1));
    m_timer_event--;
  }
}



void player::external_data (Player P)     //Not receiving any signal
{
   /*// this is called when data is received
   lock ();
   if(players.size() < 7)
   {
     int i;
     int check = -1;
     std::cout << "Player data has been received" << std::endl;
     if(strcmp(P.game_uid,m_P.game_uid) == 0)
     {
       for (i = 0; i < players.size(); i++) {
         if(strcmp(players[i].uid, P.uid) == 0)
         {
           check = i;
           break;
         }
         players.push_back(P);
       }
     }
     std::cout << players.size() << "aaaaaaaaaaaaaaaaaa" << std::endl;
   }
   unlock ();
   */
}

void player::external_data (Dealer D)
{
   // this is called when data is received
   lock ();
   m_D = D;
   m_Dealer_recv = true;
   std::cout << "Dealer data has been received" << std::endl;
   manage_state ();
   unlock ();
}

void player::external_data (Game G)
{
   // only care about games
   // we are in.
   //
   // this routine creates two possible eventsd
   // they are mutually exclusive
   //     m_Game_recv      when the game uids match
   //     m_Game_recv_idx  when the game uids and the idx match
   lock ();

   // first, the game needs to match
   boost::uuids::uuid t;
   memcpy ( &t, G.game_uid, sizeof ( t ) );
   if (t == m_current_game_uuid)
   {
        m_G = G;  // it is the state of our game, so
                  // store it
        m_Game_recv = true;
        // now to check if it is our turn
        unsigned int i = G.active_player;
        boost::uuids::uuid active_player_uuid;
        memcpy ( &active_player_uuid,
                 G.p[i].uid,
                 sizeof ( active_player_uuid ) );
        if ( m_my_uid == active_player_uuid )
        {
            // and last, need to be sure we are
            // 'playing' the game

            if ( G.gstate == playing )
            {
               m_Game_recv_idx = true;
               m_Game_recv = false;
            }
        }
   }
   if (m_Game_recv || m_Game_recv_idx )
   {
      if ( m_Game_recv )
      {
        std::cout << "Game (uid matched) received" << std::endl;
      }
      else if ( m_Game_recv_idx )
      {
        std::cout << "Game (uid matched and idx ) received" << std::endl;
        act = true;
      }
      memcpy(p_cards,G.p[G.active_player].cards,sizeof(p_cards));
      memcpy(d_cards,G.dealer_cards,sizeof(p_cards));
      set_card_id();
      manage_state ();
      m_timer_event = 15;     //15 second countdown after game data is recieved
      TIMER(15);
   }
   else
      // single player, this is a problem.  otherwise it is OK
      { std::cout << "Game was ignored " << std::endl;
    }


    if (d_down)         //if double down has been pressed.. 2nd action is stand... implements automatically without user interaction
    {
      boost::this_thread::sleep_for(boost::chrono::seconds(2));
      user_input("stand");
      d_down = false;
    }


   unlock ();
}


void player::user_input (std::string I)     //user input handler...
{
   lock ();
   m_user_event_string = I;
   m_user_event = true;
   std::cout << "User input received: " << m_user_event_string << std::endl;
   manage_state ();
   unlock ();
}

void player::setName (std::string Name )        //set player name
{
   strncpy ( m_P.name, Name.c_str(), sizeof (m_P.name) - 1 );
}


std::string player::getName()       //get player name
{
  return m_P.name;
}

bool player::get_m_Dealer_recv()        //get dealer receive signal
{
  return m_Dealer_recv;
}

std::vector<Dealer> player::getDealer_list(){       //returns available dealer list
  return m_dealer_list;
}

int player::get_hands_won()                 //returns hands won
{
  return hands_won;
}

int player::get_hands_played()        //returns games played
{
  return hands_played;
}

void player::set_play_style(int x)        //sets player play style
{
 play_style = x;
}

bool player::get_act()                //return player action signal
{
  return act;
}

std::string player::getStyle(){                     //return player style
  string res;
  switch(play_style)
  {
    case 1: res = "Manual"; break;
    case 2: res = "Basic";  break;
    case 3: res = "Aggressive"; break;
    case 4: res = "Counting"; break;
    case 5: res = "Conservative"; break;
  }
  return res;
}

std::string player::getDealerName(){              //return dealer name
return m_dealer_list[m_dealer_idx].name;
}

std::string player::getDealerID(){                      //return dealer id
  boost::uuids::uuid u;
  memcpy (m_dealer_list[m_dealer_idx].uid , &u, 16 );
  string s = boost::uuids::to_string(u);
return s;
}

std::string player::get_game_uid()                          //return game id
{
  string s = boost::uuids::to_string(m_current_game_uuid);
return s;
}

std::string player::getPlayerID() {       //return player id
  return uid;
}

void player::setUID(std::string s)        //set player id
{
  uid = s;
}

float player::getBalance()          //return player balance
{
  return m_balance;
}

int player::getPlayerState() {                            //return player state
    return m_player_state;
}

void player::setDealerIDX(int x)                  //set joined dealer id no.
{
  m_dealer_idx = x;
}

int* player::get_p_cards()                          //returns player array of cards
{
  return p_card_id;
}

int* player::get_d_cards(){                 //returns dealer array of cards
  return d_card_id;
}

void player::set_card_id(){                     //set card image value so that it is easy to retrieve the card image
  int i;                                      //0-face down, 1-13 spade, 14-26 diamonds, 27-39 hearts, 40-52 clubs
  for (i=0;i<10;i++)
  {
     if ( p_cards[i].valid )
     {
       int x = 0;
       switch ( p_cards[i].suite )
       {
         case hearts:x += 39;break;
         case diamonds:x += 26;break;
         case clubs:x += 0;break;
         case spades:x += 13;break;
       }

       switch ( p_cards[i].card )
       {
          case ace:x += 1;break;
          case two:x += 2;break;
          case three:x += 3;break;
          case four:x += 4;break;
          case five:x += 5;break;
          case six:x += 6;break;
          case seven:x += 7;break;
          case eight:x += 8;break;
          case nine:x += 9;break;
          case ten:x += 10;break;
          case jack:x += 11;break;
          case queen:x += 12;break;
          case king:x += 13;break;
       }
       p_card_id[i] = x;
     }
  }
  for (i=0;i<10;i++)
  {
    if ( d_cards[i].valid )
    {
      int x = 0;
      switch ( d_cards[i].suite )
      {
        case hearts:x += 39;break;
        case diamonds:x += 26;break;
        case clubs:x += 0;break;
        case spades:x += 13;break;
      }

      switch ( d_cards[i].card )
      {
         case ace:x += 1;break;
         case two:x += 2;break;
         case three:x += 3;break;
         case four:x += 4;break;
         case five:x += 5;break;
         case six:x += 6;break;
         case seven:x += 7;break;
         case eight:x += 8;break;
         case nine:x += 9;break;
         case ten:x += 10;break;
         case jack:x += 11;break;
         case queen:x += 12;break;
         case king:x += 13;break;
      }
      d_card_id[i] = x;
    }
  }

}

int player::get_value()           //return player card value
{
  return value;
}

int player::get_d_value()                 //return dealer card value
{
  return d_value;
}

std::string player::getSuggestion()             //return player startegy suggestion
{
  return suggest;
}

int player::get_win()                   //return player game state
{
  return win;
}

void player::new_game()                         //when new game button is pressed
{
  d_down = false;
  d_value = 0;                              //initialize the card value to 0
  value = 0;



  win = -1;                           //game state is in progress
  suggest = "";
  int i;
  for(i = 0; i< 10; i++)                //card image value is set to 100 so that there is no image
  {
    p_card_id[i] = 100;
    d_card_id[i] = 100;
  }
  bet_amt = 0;                          //reset bet amount
}

void player::bet_game()                             //when bet button is pressed
{
  m_balance = m_balance - bet_amt;              //total balance is decreased and 15 seconds countdown time is set
  m_timer_event    = 15;
  TIMER(15);
}

int player::get_timer_event()           //return countdown timer
{
  return m_timer_event;
}


player::player ()
{
  // member variables
  start = true;                       //game start flag
  act = false;                        //player action flag
  d_down = false;                         //double down flag
  suggest = "";               //strategy suggestion
  m_player_state = Init;
  m_balance = 1000.0;                   //initial player balance
  m_P.balance = m_balance;
  m_dealer_list.clear ();
  m_timer_thread = NULL;

  bet_amt = 0.0;
  value = 0;
  d_value = 0;
  win = -1;
  int i;
  for(i = 0; i< 10; i++)
  {
    p_card_id[i] = 100;
    d_card_id[i] = 100;
  }
  // member objects
  p_io = new dds_io<Player,PlayerSeq,PlayerTypeSupport_var,PlayerTypeSupport,PlayerDataWriter_var,
                    PlayerDataWriter,PlayerDataReader_var,PlayerDataReader>
               ( (char*) "player", true, false );

  d_io = new dds_io<Dealer,DealerSeq,DealerTypeSupport_var,DealerTypeSupport,DealerDataWriter_var,
                    DealerDataWriter,DealerDataReader_var,DealerDataReader>
               ( (char*) "dealer", false, true );

  g_io = new dds_io<Game,GameSeq,GameTypeSupport_var,GameTypeSupport,GameDataWriter_var,
                    GameDataWriter,GameDataReader_var,GameDataReader>
               ( (char*) "game", false, true );

  // event flags
  m_timer_event    = 15;
  m_user_event     = false;
  m_Player_recv    = false;
  m_Game_recv      = false;
  m_Game_recv_idx  = false;
  m_Dealer_recv    = false;

   hands_won = 0;
   hands_played = 0;
   play_style = 1;                  //default play style
}

player::~player ()
{
}

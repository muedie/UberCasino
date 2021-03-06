#include "lobby_controller.h"
#include "table_controller.h"
#include "player.h"


void tab_thread ( int seconds, std::function <void(void)> callback)         //function to call callback function and then sleep
{
  while(1)
  {
    boost::this_thread::sleep_for(boost::chrono::seconds(seconds));
    callback ();
  }
}


Table_controller::Table_controller(player& p) : Table_view() , _p{p}{
update = new boost::thread ( tab_thread , 1, std::bind ( &Table_controller::ClickedRefresh_i , this ) );  //thread to check conditions per second
player_name->value(_p.getName().c_str());
play_style->value(_p.getStyle().c_str());

dealer_name->value(_p.getDealerName().c_str());
string s = _p.getDealerID();
dealer_id->value(s.c_str());
game_id->value(_p.get_game_uid().c_str());

  btn_leave->callback(ClickedLeave, (void*)this);       //leave button callback
  btn_new->callback(ClickedNewGame, (void*)this);     //new button callback
  double_down->callback(ClickedDoubledown, (void*)this);
  split->callback(ClickedSplit, (void*)this);
  stand->callback(ClickedStand, (void*)this);
  hit->callback(ClickedHit, (void*)this);
  bet->callback(ClickedBet, (void*)this);
}

void Table_controller::ClickedLeave(Fl_Widget* w, void* data)
{
  ((Table_controller*)data)->ClickedLeave_i();
}

void Table_controller::ClickedNewGame(Fl_Widget* w, void* data)
{
  ((Table_controller*)data)->ClickedNewGame_i();
}

void Table_controller::ClickedDoubledown(Fl_Widget* w, void* data)
{
  ((Table_controller*)data)->ClickedDoubledown_i();
}


void Table_controller::ClickedSplit(Fl_Widget* w, void* data)
{
  ((Table_controller*)data)->ClickedSplit_i();
}

void Table_controller::ClickedStand(Fl_Widget* w, void* data)
{
  ((Table_controller*)data)->ClickedStand_i();
}

void Table_controller::ClickedHit(Fl_Widget* w, void* data)
{
  ((Table_controller*)data)->ClickedHit_i();
}

void Table_controller::ClickedBet(Fl_Widget* w, void* data)
{
  ((Table_controller*)data)->ClickedBet_i();
}

void Table_controller::ClickedRefresh_i()       //check the current status of game.. is ran continously with the help of thread
{
  int time = _p.get_timer_event();              //get countdown time
  cd_time->value(std::to_string(time).c_str());
  if (_p.get_win() != -1)         //check if the game is won.. deactivates all other button except new and leave button
  {
    btn_new->activate();
    btn_leave->activate();
    hit->deactivate();
    stand->deactivate();
    double_down->deactivate();
  }
  player_suggestion->value(_p.getSuggestion().c_str());
  float bal = _p.getBalance();
  int b;
  b = _p.get_value();

  player_count->value(std::to_string(b).c_str());
  b = _p.get_d_value();
  dealer_count->value(std::to_string(b).c_str());
  b = int(bal + 0.5);
  balance->value(std::to_string(b).c_str());
  float a = _p.bet_amt;
  b = int(a + 0.5);
  std::string s = "$" + std::to_string(b);
  betting_amount->value(s.c_str());
  int p[10];                //player cards array
  memcpy(p,_p.get_p_cards(),sizeof(p));
  int d[10];                  //dealer cards array
  memcpy(d,_p.get_d_cards(),sizeof(d));
  int i;
  for(i = 0; i< 10; i++)            //for loop check for player cards and load correct cards in window
  {
    if(p[i] < 53){                  //checks if the card is valid or not
      pl_card[i]->image(card[p[i]]);
    }
    else
    {
      pl_card[i]->image(NULL);          //invalid cards does not get image
    }
    if(d[i] < 53)
    {
      dl_card[i]->image(card[d[i]]);
    }
    else if(d[1] > 52 && d[2] > 52 && d[0] < 53)        //2nd card of dealer in faced down
      {
        dl_card[1]->image(card[0]);
      }
    else
    {
      dl_card[i]->image(NULL);
    }
  }
  if (_p.get_act() && !_p.start)      //check for player action..hit stand and double down button gets activated
  {
    hit->activate();
    stand->activate();
    double_down->activate();

  }
  switch(_p.get_win())          //checks the game current condition..0-tie, 1-win, 2-lose, 4-blackjack, -1-in progress
  {
    case 0: result1->image(tie_img); result2->image(tie_img); break;
    case 1: result1->image(win_img); result2->image(win_img); break;
    case 2: result1->image(lose_img); result2->image(lose_img); break;
    case 4: result1->image(bj_img); result2->image(bj_img); break;
    case -1: result1->image(NULL); result2->image(NULL); break;
  }
  if ( time == 0)       //if the countdown time reaches 0, all buttons gets deactivated except leave button game
  {
    result1->image(timeout_img);
    result2->image(timeout_img);
    hit->deactivate();
    stand->deactivate();
    double_down->deactivate();
    btn_new->deactivate();
    btn_leave->activate();
    bet->deactivate();
    std::cout << "TIMEOUT" <<std::endl;
  }
  this->damage();       //all widgets all damaged to be redrawn again.. horrible hack
  this->redraw();
}

//Implement model here
void Table_controller::ClickedDoubledown_i()      //double down call back function
{
  hit->deactivate();
  stand->deactivate();
  double_down->deactivate();
  _p.user_input("dd");
}


void Table_controller::ClickedLeave_i()       //leave button call back function
{
  if(update != NULL)                  //deletes the active thread
  {
    update->interrupt ();
    delete ( update );
    update = NULL;
  }
  hide();
  Lobby_controller win(_p);
  Fl::run();
}

void Table_controller::ClickedNewGame_i()       //new game call back function
{
  bet->activate();
  btn_new->deactivate();
  _p.new_game();
}

void Table_controller::ClickedSplit_i()
{

}


void Table_controller::ClickedStand_i()       //stand button call back function
{
  hit->deactivate();
  stand->deactivate();
  double_down->deactivate();
  _p.user_input("stand");
}

void Table_controller::ClickedHit_i()       //hit button call back function
{
  hit->deactivate();
  stand->deactivate();
  double_down->deactivate();
  _p.user_input("hit");
}

void Table_controller::ClickedBet_i()     //clicked bet call back function
{
  bet->deactivate();
  hit->activate();
  stand->activate();
  double_down->activate();
  btn_leave->deactivate();
  _p.start = false;
  float a = (float) spn_bet->value();     //get value from spinner
  _p.bet_amt = a;
  _p.bet_game();
  _p.user_input("bet");
}

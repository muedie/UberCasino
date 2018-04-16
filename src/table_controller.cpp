#include "lobby_controller.h"
#include "table_controller.h"
#include "player.h"

void time_cb(void *v)
{
  Fl::repeat_timeout(double(1.0)/15, time_cb);
}

void tab_thread ( int seconds, std::function <void(void)> callback)
{
  // this routine is created as a posix thread.
  boost::this_thread::sleep_for(boost::chrono::seconds(seconds));
  callback ();
}


Table_controller::Table_controller(player& p) : Table_view() , _p{p}{
update = new boost::thread ( tab_thread , 1 , std::bind ( &Table_controller::Update , this ) );
player_name->value(_p.getName().c_str());
play_style->value(_p.getStyle().c_str());

dealer_name->value(_p.getDealerName().c_str());
string s = _p.getDealerID();
dealer_id->value(s.c_str());

  btn_leave->callback(ClickedLeave, (void*)this);
  double_down->callback(ClickedDoubledown, (void*)this);
  split->callback(ClickedSplit, (void*)this);
  stand->callback(ClickedStand, (void*)this);
  hit->callback(ClickedHit, (void*)this);
  bet->callback(ClickedBet, (void*)this);
}

void Table_controller::Update()
{
  Fl::lock();
  while(1)
  {
    float bal = _p.getBalance();
    int b = int(bal + 0.5);
    balance->value(std::to_string(b).c_str());
  }
  Fl::unlock();
}

void Table_controller::ClickedLeave(Fl_Widget* w, void* data)
{
  ((Table_controller*)data)->ClickedLeave_i();
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

void Table_controller::ClickedLeave_i()
{
  hide();
  Lobby_controller win(_p);
  Fl::add_timeout(0.1,time_cb);
  Fl::run();
}

//Implement model here
void Table_controller::ClickedDoubledown_i()
{
  hide();
  Lobby_controller win(_p);
  Fl::run();
}


void Table_controller::ClickedSplit_i()
{

}


void Table_controller::ClickedStand_i()
{
  _p.user_input("stand");
}

void Table_controller::ClickedHit_i()
{
  _p.user_input("hit");
}

void Table_controller::ClickedBet_i()
{
  float a = (float) spn_bet->value();
  _p.bet_amt = a;
  std::string s = std::to_string(a);
  betting_amount->value(s.c_str());
  _p.user_input("bet");
}

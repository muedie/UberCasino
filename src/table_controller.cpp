#include "lobby_controller.h"
#include "table_controller.h"
#include "player.h"


void tab_thread ( int seconds, std::function <void(void)> callback)
{
  while(1)
  {
    boost::this_thread::sleep_for(boost::chrono::seconds(seconds));
    callback ();
  }
}


Table_controller::Table_controller(player& p) : Table_view() , _p{p}{
update = new boost::thread ( tab_thread , 1, std::bind ( &Table_controller::ClickedRefresh_i , this ) );
player_name->value(_p.getName().c_str());
play_style->value(_p.getStyle().c_str());

dealer_name->value(_p.getDealerName().c_str());
string s = _p.getDealerID();
dealer_id->value(s.c_str());
game_id->value(_p.get_game_uid().c_str());

  btn_refresh->callback(ClickedRefresh, (void*)this);
  double_down->callback(ClickedDoubledown, (void*)this);
  split->callback(ClickedSplit, (void*)this);
  stand->callback(ClickedStand, (void*)this);
  hit->callback(ClickedHit, (void*)this);
  bet->callback(ClickedBet, (void*)this);
}

void Table_controller::ClickedRefresh(Fl_Widget* w, void* data)
{
  ((Table_controller*)data)->ClickedRefresh_i();
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

void Table_controller::ClickedRefresh_i()
{
  if (_p.start)
  {
    bet->activate();
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
  int p[10];
  memcpy(p,_p.get_p_cards(),sizeof(p));
  int d[10];
  memcpy(d,_p.get_d_cards(),sizeof(d));
  int i;
  for(i = 0; i< 10; i++)
  {
    if(p[i] < 53){
      pl_card[i]->image(card[p[i]]);
    }
    else
    {
      pl_card[i]->image(NULL);
    }
    if(d[i] < 53)
    {
      dl_card[i]->image(card[d[i]]);
    }
    else if(d[1] > 52 && d[2] > 52 && d[0] < 53)
      {
        dl_card[1]->image(card[0]);
      }
    else
    {
      dl_card[i]->image(NULL);
    }
  }
  if (_p.get_act() && !_p.start)
  {
    hit->activate();
    stand->activate();
    double_down->activate();

  }
  switch(_p.get_win())
  {
    case 0: result1->image(tie_img); result2->image(tie_img); break;
    case 1: result1->image(win_img); result2->image(win_img); break;
    case 2: result1->image(lose_img); result2->image(lose_img); break;
    case -1: result1->image(NULL); result2->image(NULL); break;
  }
  this->damage();
  this->redraw();
}

//Implement model here
void Table_controller::ClickedDoubledown_i()
{
  hit->deactivate();
  stand->deactivate();
  double_down->deactivate();
  _p.user_input("dd");
}


void Table_controller::ClickedSplit_i()
{

}


void Table_controller::ClickedStand_i()
{
  hit->deactivate();
  stand->deactivate();
  double_down->deactivate();
  _p.user_input("stand");
}

void Table_controller::ClickedHit_i()
{
  hit->deactivate();
  stand->deactivate();
  double_down->deactivate();
  _p.user_input("hit");
}

void Table_controller::ClickedBet_i()
{
  betting_box->show();
  bet->deactivate();
  hit->activate();
  stand->activate();
  double_down->activate();
  _p.start = false;
  float a = (float) spn_bet->value();
  _p.bet_amt = a;
  _p.new_game();
  _p.user_input("bet");
}

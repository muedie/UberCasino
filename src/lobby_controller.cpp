#include "lobby_controller.h"
#include "login_controller.h"
#include "table_controller.h"


Lobby_controller::Lobby_controller(player& p) : Lobby_view() , _p{p} {
  player_name->value(_p.getName().c_str());
  float bal = _p.m_P.balance;
  int b = int(bal + 0.5);
  string uid = _p.m_P.uid;
  player_balance->value(std::to_string(b).c_str());
  player_id->value(uid.c_str());
  player_games_played->value(std::to_string(_p.get_hands_played()).c_str());
  player_hands_won->value(std::to_string(_p.get_hands_won()).c_str());

  manual->when(FL_WHEN_CHANGED);
  basic->when(FL_WHEN_CHANGED);
  aggressive->when(FL_WHEN_CHANGED);
  counting->when(FL_WHEN_CHANGED);
  conservative->when(FL_WHEN_CHANGED);
  manual->callback(ClickedRound, (void*) "1");
  basic->callback(ClickedRound, (void*) "2");
  aggressive->callback(ClickedRound,(void*) "3");
  counting->callback(ClickedRound, (void*) "4");
  conservative->callback(ClickedRound, (void*) "5");
  logout_btn->callback(ClickedLogout, this);
  refresh_btn->callback(ClickedRefresh, (void*)this);
  join_btn->callback(ClickedJoin, (void*) "0");
  join_btn2->callback(ClickedJoin, (void*) "1");
  join_btn3->callback(ClickedJoin, (void*) "2");
  join_btn4->callback(ClickedJoin, (void*) "3");
}

void Lobby_controller::ClickedLogout(Fl_Widget* w, void* data)
{
  ((Lobby_controller*)data)->ClickedLogout_i();
}

void Lobby_controller::ClickedRefresh(Fl_Widget* w, void* data)
{
  ((Lobby_controller*)data)->ClickedRefresh_i();
}

void Lobby_controller::ClickedJoin(Fl_Widget* w, void* data)
{
  char * x = (char*) data;
  ((Lobby_controller*)data)->ClickedJoin_i(x);
}

void Lobby_controller::ClickedRound(Fl_Widget* w, void* data)
{
  int x = std::stoi((char*) data);
  ((Lobby_controller*)data)->ClickedRound_i(x);
}

void Lobby_controller::ClickedRound_i(int x)
{
  _p.set_play_style(x);
}


//Implement your model here in these call back function.

void Lobby_controller::ClickedRefresh_i()
{
    vector<Dealer> v = _p.getDealer_list();
    string s1, s2;
    switch (v.size()) {
      case 4:
      dealer_info4->show();
      s1 = v[3].name;
      s2 = v[3].uid;
      dealer_name4->value(s1.c_str());
      dealer_id4->value(s2.c_str());

      case 3:
      dealer_info3->show();
      s1 = v[2].name;
      s2 = v[2].uid;
      dealer_name3->value(s1.c_str());
      dealer_id3->value(s2.c_str());

      case 2:
      dealer_info2->show();
      s1 = v[1].name;
      s2 = v[1].uid;
      dealer_name2->value(s1.c_str());
      dealer_id2->value(s2.c_str());

      case 1:
      dealer_info->show();
      s1 = v[0].name;
      s2 = v[0].uid;
      dealer_name->value(s1.c_str());
      dealer_id->value(s2.c_str());

      default: break;
    }
}

void Lobby_controller::ClickedLogout_i()
{
  hide();
  _p = player();
  Login_controller win(_p);
  Fl::run();
}

void Lobby_controller::ClickedJoin_i(char* x)
{
  hide();
  _p.user_input(x);
  Table_controller win(_p);
  Fl::run();
}

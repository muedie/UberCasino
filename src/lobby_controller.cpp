#include "lobby_controller.h"
#include "login_controller.h"
#include "table_controller.h"


Lobby_controller::Lobby_controller(player& p) : Lobby_view() , _p{p} {
  player_name->value(_p.getName().c_str());
  player_balance->value(std::to_string(_p.m_P.balance).c_str());

  logout_btn->callback(ClickedLogout, this);
  refresh_btn->callback(ClickedRefresh, (void*)this);
  join_btn->callback(ClickedJoin, (void*)this);
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
  ((Lobby_controller*)data)->ClickedJoin_i();
}


//Implement your model here in these call back function.

void Lobby_controller::ClickedRefresh_i()
{
    vector<Dealer> v = _p.getDealer_list();
    if (v.size() != 0)
    {
      string s1 = v[0].name;
      string s2 = v[0].uid;
      dealer_name->value(s1.c_str());
      dealer_id->value(s2.c_str());
    }

}

void Lobby_controller::ClickedLogout_i()
{
  hide();
  _p.setClear();
  Login_controller win(_p);
  Fl::run();
}

void Lobby_controller::ClickedJoin_i()
{
  hide();
  _p.user_input("0");
  Table_controller win(_p);
  Fl::run();
}

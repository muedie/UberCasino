#include "lobby_controller.h"
#include "login_controller.h"
#include "table_controller.h"


Lobby_controller::Lobby_controller(Player& p) : Lobby_view() , _p{p} {
  player_name->value(_p.getName().c_str());
  //player_balance->value(std::to_string(_p.getBalance()).c_str());

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
  hide();
}

void Lobby_controller::ClickedLogout_i()
{
  hide();
  Login_controller win(_p);
  Fl::run();
}

void Lobby_controller::ClickedJoin_i()
{
  hide();
  Table_controller win(_p);
  Fl::run();
}

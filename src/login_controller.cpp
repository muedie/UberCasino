#include "login_controller.h"
#include "lobby_controller.h"


#include <string>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>


Login_controller::Login_controller(player& p) : Login_view(), _p{p} {
  login_btn->callback(ClickedLogin, this);
  quit_btn->callback(ClickedQuit, (void*)this);
}

void Login_controller::ClickedLogin(Fl_Widget* w, void* data)
{
  ((Login_controller*)data)->ClickedLogin_i();
}

void Login_controller::ClickedQuit(Fl_Widget* w, void* data)
{
  ((Login_controller*)data)->ClickedQuit_i();
}


void Login_controller::ClickedQuit_i()
{
  hide();
}

void Login_controller::ClickedLogin_i()
{
  std::string s = name_input->value();
  if (s == "")
  {
    s = "Player1";
  }
  boost::uuids::uuid uuid = boost::uuids::random_generator()();
  _p.setName(s);
  memcpy ( _p.m_P.uid, &uuid, sizeof ( _p.m_P.uid ) );
  hide();
 Lobby_controller win(_p);
  Fl::run();
}

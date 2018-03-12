#include "login_controller.h"
#include "lobby_controller.h"


Login_controller::Login_controller() : Login_view() {
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
  //char* s = name_input->value();
  hide();
 Lobby_controller win;
  Fl::run();
}

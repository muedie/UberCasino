#include "login_controller.h"
#include "player.h"

static player* PTR;     //external variable so that it will point to same player object
#include "callback.h"

int main(int argc, char const *argv[]) {
  player p = player();
  PTR = &p;
  Login_controller win(p);      //start the main_window

  return (Fl::run());
}

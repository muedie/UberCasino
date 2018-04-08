#include "login_controller.h"
#include "lobby_view.h"

int main(int argc, char const *argv[]) {
  Player p;
  Login_controller win(p);
  //Lobby_view win;
  return (Fl::run());
}

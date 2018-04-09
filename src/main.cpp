#include "login_controller.h"
#include "player.h"

player* PTR;
#include "callback.h"

int main(int argc, char const *argv[]) {
  player p = player();
 PTR = &p;
  Login_controller win(p);

  return (Fl::run());
}

#ifndef LOGIN_C_H
#define LOGIN_C_H

#include "login_view.h"
#include "player_model.h"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_JPEG_Image.H>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Login_controller : public Login_view {

private:
  Player& _p;

public:
  Login_controller (Player& p);
  static void ClickedQuit(Fl_Widget* w, void* data);
  static void ClickedLogin(Fl_Widget* w, void* data);
  void ClickedQuit_i();
  void ClickedLogin_i();

};
#endif

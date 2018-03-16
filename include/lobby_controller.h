#ifndef LOBBY_C_H
#define LOBBY_C_H

#include "lobby_view.h"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_JPEG_Image.H>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Lobby_controller : public Lobby_view {

private:


public:
  Lobby_controller ();
  static void ClickedLogout(Fl_Widget* w, void* data);
  static void ClickedRefresh(Fl_Widget* w, void* data);
  static void ClickedJoin(Fl_Widget* w, void* data);
  void ClickedLogout_i();
  void ClickedRefresh_i();
  void ClickedJoin_i();

};
#endif

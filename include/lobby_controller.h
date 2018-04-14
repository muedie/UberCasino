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
#include "player.h"

class Lobby_controller : public Lobby_view {

private:
  player& _p;
  boost::thread *lobby_thread;

public:
  Lobby_controller (player& p);
  static void ClickedLogout(Fl_Widget* w, void* data);
  static void ClickedRefresh(Fl_Widget* w, void* data);
  static void ClickedJoin1(Fl_Widget* w, void* data);
  static void ClickedJoin2(Fl_Widget* w, void* data);
  static void ClickedJoin3(Fl_Widget* w, void* data);
  static void ClickedJoin4(Fl_Widget* w, void* data);
  static void ClickedRound1(Fl_Widget* w, void* data);
  static void ClickedRound2(Fl_Widget* w, void* data);
  static void ClickedRound3(Fl_Widget* w, void* data);
  static void ClickedRound4(Fl_Widget* w, void* data);
  static void ClickedRound5(Fl_Widget* w, void* data);
  void ClickedLogout_i();
  void ClickedRefresh_i();
  void ClickedJoin1_i();
  void ClickedJoin2_i();
  void ClickedJoin3_i();
  void ClickedJoin4_i();
  void ClickedRound1_i();
  void ClickedRound2_i();
  void ClickedRound3_i();
  void ClickedRound4_i();
  void ClickedRound5_i();

};
#endif

#ifndef TABLE_C_H
#define TABLE_C_H

#include "table_view.h"
#include "player.h"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Spinner.H>

#include <boost/thread.hpp>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Table_controller : public Table_view {

private:
  player& _p;
  boost::thread *update;

public:
  Table_controller (player& p);
  static void ClickedLeave(Fl_Widget* w, void* data);
  static void ClickedNewGame(Fl_Widget* w, void* data);
  static void ClickedDoubledown(Fl_Widget* w, void* data);
  static void ClickedSplit(Fl_Widget* w, void* data);
  static void ClickedStand(Fl_Widget* w, void* data);
  static void ClickedHit(Fl_Widget* w, void* data);
  static void ClickedBet(Fl_Widget* w, void* data);


  void ClickedRefresh_i();
  void ClickedNewGame_i();
  void ClickedLeave_i();
  void ClickedDoubledown_i();
  void ClickedSplit_i();
  void ClickedStand_i();
  void ClickedHit_i();
  void ClickedBet_i();


};
#endif

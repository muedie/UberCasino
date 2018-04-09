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

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Table_controller : public Table_view {

private:
  player& _p;

public:
  Table_controller (player& p);
  static void ClickedLeave(Fl_Widget* w, void* data);

  void ClickedLeave_i();


};
#endif

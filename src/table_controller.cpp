#include "lobby_controller.h"
#include "table_controller.h"


Table_controller::Table_controller(player& p) : Table_view() , _p{p}{
  btn_leave->callback(ClickedLeave, (void*)this);
 double_down->callback(ClickedDoubledown, (void*)this);
  split->callback(ClickedSplit, (void*)this);
  stand->callback(ClickedStand, (void*)this);
  hit->callback(ClickedHit, (void*)this);
  bet->callback(ClickedBet, (void*)this);


}

void Table_controller::ClickedLeave(Fl_Widget* w, void* data)
{
  ((Table_controller*)data)->ClickedLeave_i();
}
void Table_controller::ClickedDoubledown(Fl_Widget* w, void* data)
{
  ((Table_controller*)data)->ClickedDoubledown_i();
}


void Table_controller::ClickedSplit(Fl_Widget* w, void* data)
{
  ((Table_controller*)data)->ClickedSplit_i();
}

void Table_controller::ClickedStand(Fl_Widget* w, void* data)
{
  ((Table_controller*)data)->ClickedStand_i();
}

void Table_controller::ClickedHit(Fl_Widget* w, void* data)
{
  ((Table_controller*)data)->ClickedHit_i();
}

void Table_controller::ClickedBet(Fl_Widget* w, void* data)
{
  ((Table_controller*)data)->ClickedBet_i();
}

void Table_controller::ClickedLeave_i()
{
  //char* s = name_input->value();
  hide();
  Lobby_controller win(_p);
  Fl::run();
}




//Implement model here


void Table_controller::ClickedDoubledown_i()
{
  //char* s = name_input->value();
  hide();
  Lobby_controller win(_p);
  Fl::run();
}


void Table_controller::ClickedSplit_i()
{
  //char* s = name_input->value();
  hide();
  Lobby_controller win(_p);
  Fl::run();
}


void Table_controller::ClickedStand_i()
{
  //char* s = name_input->value();
  hide();
  Lobby_controller win(_p);
  Fl::run();
}

void Table_controller::ClickedHit_i()
{
  //char* s = name_input->value();
  hide();
  Lobby_controller win(_p);
  Fl::run();
}



void Table_controller::ClickedBet_i()
{
  //char* s = name_input->value();
  hide();
  Lobby_controller win(_p);
  Fl::run();
}

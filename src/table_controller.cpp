#include "lobby_controller.h"
#include "table_controller.h"


Table_controller::Table_controller() : Table_view() {
  btn_leave->callback(ClickedLeave, this);

}


void Table_controller::ClickedLeave(Fl_Widget* w, void* data)
{
  ((Table_controller*)data)->ClickedLeave_i();
}



void Table_controller::ClickedLeave_i()
{
  //char* s = name_input->value();
  hide();
  Lobby_controller win;
  Fl::run();
}

#include "login.h"


Login_view::Login_view() : Fl_Window(430, 475, "Login")
{
  begin();
  background_img = new Fl_JPEG_Image("images/login.jpeg");
  main_box = new Fl_Box(0, 0, 430, 475);
  main_box->image(background_img);

  title_box = new Fl_Box(48, 40, 330, 190);
  title_box->box(FL_GLEAM_UP_BOX);
  title_box->color(FL_FOREGROUND_COLOR);

  title = new Fl_Text_Display(81, 207, 257, 0, "Welcome to Jack Black\'s BlackJack");
  title->box(FL_NO_BOX);
  title->labeltype(FL_SHADOW_LABEL);
  title->labelfont(3);
  title->labelsize(38);
  title->labelcolor((Fl_Color)26);
  title->align(Fl_Align(129));

  name_box = new Fl_Box(84, 273, 245, 40, "Enter your name:");
  name_box->box(FL_GLEAM_UP_BOX);
  name_box->color(FL_FOREGROUND_COLOR);
  name_box->labelfont(1);
  name_box->labelsize(20);
  name_box->labelcolor((Fl_Color)26);

  name_input = new Fl_Input(85, 327, 245 , 30);
  name_input->labelsize(24);
  name_input->textsize(20);

  login_btn = new Fl_Button(154, 380, 105, 33, "Login");
  login_btn->box(FL_GLEAM_UP_BOX);
  login_btn->color((Fl_Color)178);
  login_btn->labelfont(1);
  login_btn->labelsize(18);
  login_btn->labelcolor((Fl_Color)26);

  quit_btn = new Fl_Button(154, 420, 105, 33, "Quit");
  quit_btn->box(FL_GLEAM_UP_BOX);
  quit_btn->color((Fl_Color)178);
  quit_btn->labelfont(1);
  quit_btn->labelsize(18);
  quit_btn->labelcolor((Fl_Color)26);

  end();
  show();

}

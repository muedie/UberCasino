#ifndef LOGIN_H
#define LOGIN_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_JPEG_Image.H>

#include <stdio.h>
#include <stdlib.h>

class Login_view: public Fl_Window {
protected:
  Fl_Box* main_box;
  Fl_Box* title_box;
  Fl_Box* name_box;
  Fl_Input* name_input;
  Fl_Button* login_btn;
  Fl_Button* quit_btn;
  Fl_Text_Display* title;
  Fl_JPEG_Image* background_img;

public:
  Login_view();


};

#endif

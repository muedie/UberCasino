#ifndef LOBBY_H
#define LOBBY_H

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

class Lobby_view: public Fl_Window {
protected:
  Fl_Box* main_box;
  Fl_Scroll* scroll_window;
  Fl_Group* dealer_info;
  Fl_Output* dealer_name;
  Fl_Output* dealer_id;
  Fl_Output* dealer_plcount;
  Fl_Output* dealer_ssize;
  Fl_Output* dealer_mMbet;
  Fl_Button* join_btn;
  Fl_Group* dealer_info2;
  Fl_Output* dealer_name2;
  Fl_Output* dealer_id2;
  Fl_Output* dealer_plcount2;
  Fl_Output* dealer_ssize2;
  Fl_Output* dealer_mMbet2;
  Fl_Button* join_btn2;
  Fl_Group* dealer_info3;
  Fl_Output* dealer_name3;
  Fl_Output* dealer_id3;
  Fl_Output* dealer_plcount3;
  Fl_Output* dealer_ssize3;
  Fl_Output* dealer_mMbet3;
  Fl_Button* join_btn3;
  Fl_Group* dealer_info4;
  Fl_Output* dealer_name4;
  Fl_Output* dealer_id4;
  Fl_Output* dealer_plcount4;
  Fl_Output* dealer_ssize4;
  Fl_Output* dealer_mMbet4;
  Fl_Button* join_btn4;
  Fl_Button* logout_btn;
  Fl_JPEG_Image* background_img;
  Fl_Box* side_box;
  Fl_Group* player_info;
  Fl_Text_Display* player_title;
  Fl_Output* player_name;
  Fl_Output* player_id;
  Fl_Output* player_balance;
  Fl_Output* player_games_played;
  Fl_Output* player_hands_won;
  Fl_Group* play_style;
  Fl_Text_Display* play_title;
  Fl_Round_Button* manual;
  Fl_Round_Button* basic;
  Fl_Round_Button* aggressive;
  Fl_Round_Button* counting;
  Fl_Round_Button* conservative;

public:
  Lobby_view();

};

#endif

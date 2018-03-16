// generated by Fast Light User Interface Designer (fluid) version 1.0303

#ifndef table_h
#define table_h
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Spinner.H>

#include <stdio.h>
#include <stdlib.h>

class Table_view: public Fl_Window {
protected:
  Fl_Box* main_box;
  Fl_Button* btn_leave;
  Fl_Group* dealer_info;
  Fl_Output* dealer_name;
  Fl_Output* dealer_id;
  Fl_Output* game_id;
  Fl_Output* shoe_size;
  Fl_Output* mM_bet;
  Fl_Output* dealer_count;
  Fl_Group* other_players;
  Fl_Output* player1;
  Fl_Output* player2;
  Fl_Output* player3;
  Fl_Output* player4;
  Fl_Output* player5;
  Fl_Output* player6;
  Fl_Group* player_interface;
  Fl_Button* double_down;
  Fl_Button* split;
  Fl_Button* stand;
  Fl_Button* hit;
  Fl_Button* bet;
  Fl_Output* balance;
  Fl_Spinner* spn_bet;
  Fl_Group* player_game;
  Fl_Output* player_name;
  Fl_Output* player_count;
  Fl_Output* player_suggestion;
  Fl_Group* dealer_cards;
  Fl_Box* dl_card1;
  Fl_Box* dl_card2;
  Fl_Box* dl_card3;
  Fl_Box* dl_card4;
  Fl_Box* dl_card5;
  Fl_Box* dl_card6;
  Fl_Box* dl_card7;
  Fl_Box* dl_card8;
  Fl_Box* dl_card9;
  Fl_Box* dl_card10;
  Fl_Group* player_cards;
  Fl_Box* pl_card1;
  Fl_Box* pl_card2;
  Fl_Box* pl_card3;
  Fl_Box* pl_card4;
  Fl_Box* pl_card5;
  Fl_Box* pl_card6;
  Fl_Box* pl_card7;
  Fl_Box* pl_card8;
  Fl_Box* pl_card9;
  Fl_Box* pl_card10;
  Fl_Box* betting_box;
  Fl_Output* betting_amount;

public:
  Table_view();

};

#endif

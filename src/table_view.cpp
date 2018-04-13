#include "table_view.h"

Table_view::Table_view() : Fl_Window(1325, 785, "Table")
{
  begin();

  main_box = new Fl_Box(0, 0, 1325, 785);
  main_box->box(FL_GLEAM_THIN_UP_BOX);
  main_box->color((Fl_Color)58);

  btn_leave = new Fl_Button(19, 23, 100, 55, "Leave Game");
  btn_leave->box(FL_GLEAM_THIN_UP_BOX);
  btn_leave->color((Fl_Color)138);
  btn_leave->labelfont(1);
  btn_leave->labelsize(18);
  btn_leave->labelcolor((Fl_Color)26);
  btn_leave->align(Fl_Align(FL_ALIGN_WRAP));

  {
    player_interface = new Fl_Group(25, 672, 1275, 99);
    player_interface->box(FL_GLEAM_THIN_UP_BOX);
    player_interface->color((Fl_Color)36);

    {
      double_down = new Fl_Button(1025, 698, 105, 51, "Double Down");
      double_down->box(FL_GLEAM_THIN_UP_BOX);
      double_down->color((Fl_Color)138);
      double_down->labelfont(1);
      double_down->labelsize(18);
      double_down->labelcolor((Fl_Color)26);
      double_down->align(Fl_Align(FL_ALIGN_WRAP));
      double_down->deactivate();

      split = new Fl_Button(1150, 698, 105, 51, "Split");
      split->box(FL_GLEAM_THIN_UP_BOX);
      split->color((Fl_Color)138);
      split->labelfont(1);
      split->labelsize(18);
      split->labelcolor((Fl_Color)26);
      split->align(Fl_Align(FL_ALIGN_WRAP));
      split->deactivate();

      stand = new Fl_Button(900, 698, 105, 51, "Stand");
      stand->box(FL_GLEAM_THIN_UP_BOX);
      stand->color((Fl_Color)138);
      stand->labelfont(1);
      stand->labelsize(18);
      stand->labelcolor((Fl_Color)26);
      stand->align(Fl_Align(FL_ALIGN_WRAP));
      stand->deactivate();

      hit = new Fl_Button(774, 698, 105, 51, "Hit");
      hit->box(FL_GLEAM_THIN_UP_BOX);
      hit->color((Fl_Color)138);
      hit->labelfont(1);
      hit->labelsize(18);
      hit->labelcolor((Fl_Color)26);
      hit->align(Fl_Align(FL_ALIGN_WRAP));
      hit->deactivate();

      bet = new Fl_Button(188, 698, 105, 51, "Bet");
      bet->box(FL_GLEAM_THIN_UP_BOX);
      bet->color((Fl_Color)138);
      bet->labelfont(1);
      bet->labelsize(18);
      bet->labelcolor((Fl_Color)26);
      bet->align(Fl_Align(FL_ALIGN_WRAP));
      bet->deactivate();

      balance = new Fl_Output(544, 705, 109, 35, "Balance ");
      balance->box(FL_GTK_ROUND_UP_BOX);
      balance->labelfont(1);
      balance->labelsize(24);
      balance->labelcolor((Fl_Color)26);
      balance->textsize(24);
      balance->textcolor(FL_GRAY0);

      spn_bet = new Fl_Spinner(62, 700, 105, 45);
      spn_bet->range(1,10);
      spn_bet->labelfont(1);
      spn_bet->textfont(1);
      spn_bet->textsize(24);
    }
  }

  {
    dealer_info = new Fl_Group(135, 20, 855, 121);
    dealer_info->box(FL_GLEAM_THIN_UP_BOX);
    dealer_info->color((Fl_Color)36);
    {
      dealer_name = new Fl_Output(153, 40, 320, 35);
      dealer_name->box(FL_NO_BOX);
      dealer_name->textfont(1);
      dealer_name->textsize(24);
      dealer_name->textcolor((Fl_Color)26);

      dealer_id = new Fl_Output(277, 74, 127, 35, "Dealer ID      ");
      dealer_id->box(FL_NO_BOX);
      dealer_id->labelfont(1);
      dealer_id->labelsize(16);
      dealer_id->labelcolor((Fl_Color)26);
      dealer_id->textsize(16);
      dealer_id->textcolor((Fl_Color)26);

      game_id = new Fl_Output(278, 103, 127, 22, "Game ID       ");
      game_id->box(FL_NO_BOX);
      game_id->labelfont(1);
      game_id->labelsize(16);
      game_id->labelcolor((Fl_Color)26);
      game_id->textsize(16);
      game_id->textcolor((Fl_Color)26);

      shoe_size = new Fl_Output(599, 74, 106, 31, "Shoe size     ");
      shoe_size->box(FL_NO_BOX);
      shoe_size->labelfont(1);
      shoe_size->labelsize(16);
      shoe_size->labelcolor((Fl_Color)26);
      shoe_size->textsize(16);
      shoe_size->textcolor((Fl_Color)26);

      mM_bet = new Fl_Output(600, 101, 110, 21, "Min-Max bet ");
      mM_bet->box(FL_NO_BOX);
      mM_bet->labelfont(1);
      mM_bet->labelsize(16);
      mM_bet->labelcolor((Fl_Color)26);
      mM_bet->textsize(16);
      mM_bet->textcolor((Fl_Color)26);

      dealer_count = new Fl_Output(834, 79, 127, 36, "Count ");
      dealer_count->box(FL_NO_BOX);
      dealer_count->labelfont(1);
      dealer_count->labelsize(20);
      dealer_count->labelcolor((Fl_Color)26);
      dealer_count->textsize(20);
      dealer_count->textcolor((Fl_Color)26);
    }

  }

  {
    other_players = new Fl_Group(1013, 20, 282, 349);
    other_players->box(FL_GLEAM_THIN_UP_BOX);
    other_players->color((Fl_Color)36);
    {
      player1 = new Fl_Output(1228, 39, 55, 50, "Other Players  ");
      player1->box(FL_NO_BOX);
      player1->labelfont(1);
      player1->labelsize(24);
      player1->labelcolor((Fl_Color)26);
      player1->textfont(1);
      player1->textsize(24);
      player1->textcolor((Fl_Color)26);

      player2 = new Fl_Output(1030, 92, 252, 35);
      player2->box(FL_NO_BOX);
      player2->labelfont(1);
      player2->labelsize(16);
      player2->labelcolor((Fl_Color)26);
      player2->textsize(16);
      player2->textcolor((Fl_Color)26);

      player3 = new Fl_Output(1031, 117, 252, 35);
      player3->box(FL_NO_BOX);
      player3->labelfont(1);
      player3->labelsize(16);
      player3->labelcolor((Fl_Color)26);
      player3->textsize(16);
      player3->textcolor((Fl_Color)26);

      player4 = new Fl_Output(1031, 140, 252, 35);
      player4->box(FL_NO_BOX);
      player4->labelfont(1);
      player4->labelsize(16);
      player4->labelcolor((Fl_Color)26);
      player4->textsize(16);
      player4->textcolor((Fl_Color)26);

      player5 = new Fl_Output(1031, 165, 252, 35);
      player5->box(FL_NO_BOX);
      player5->labelfont(1);
      player5->labelsize(16);
      player5->labelcolor((Fl_Color)26);
      player5->textsize(16);
      player5->textcolor((Fl_Color)26);

      player6 = new Fl_Output(1031, 190, 252, 35);
      player6->box(FL_NO_BOX);
      player6->labelfont(1);
      player6->labelsize(16);
      player6->labelcolor((Fl_Color)26);
      player6->textsize(16);
      player6->textcolor((Fl_Color)26);
    }
  }

    {
      player_game = new Fl_Group(1015, 513, 280, 144);
      player_game->box(FL_GLEAM_THIN_UP_BOX);
      player_game->color((Fl_Color)36);

      {
        player_name = new Fl_Output(1059, 536, 177, 40);
        player_name->box(FL_NO_BOX);
        player_name->labelfont(1);
        player_name->labelsize(24);
        player_name->labelcolor((Fl_Color)26);
        player_name->textfont(1);
        player_name->textsize(24);
        player_name->textcolor((Fl_Color)26);

        play_style = new Fl_Output(1151, 575, 120, 35, "Strategy       ");
        play_style->box(FL_NO_BOX);
        play_style->labelfont(1);
        play_style->labelsize(16);
        play_style->labelcolor((Fl_Color)26);
        play_style->textfont(1);
        play_style->textsize(16);
        play_style->textcolor((Fl_Color)26);

        player_count = new Fl_Output(1151, 597, 120, 35, "Count           ");
        player_count->box(FL_NO_BOX);
        player_count->labelfont(1);
        player_count->labelsize(16);
        player_count->labelcolor((Fl_Color)26);
        player_count->textsize(16);
        player_count->textcolor((Fl_Color)26);

        player_suggestion = new Fl_Output(1151, 619, 120, 35, "Suggestion   ");
        player_suggestion->box(FL_NO_BOX);
        player_suggestion->labelfont(1);
        player_suggestion->labelsize(16);
        player_suggestion->labelcolor((Fl_Color)26);
        player_suggestion->textsize(16);
        player_suggestion->textcolor((Fl_Color)26);
      }
    }

    {
      dealer_cards = new Fl_Group(42, 150, 768, 196);
      {
        dl_card1 = new Fl_Box(65, 175, 65, 85);
        dl_card1->box(FL_GTK_UP_BOX);
        dl_card1->color((Fl_Color)18);

        dl_card2 = new Fl_Box(136, 175, 65, 85);
        dl_card2->box(FL_GTK_UP_BOX);
        dl_card2->color((Fl_Color)18);

        dl_card3 = new Fl_Box(207, 176, 65, 85);
        dl_card3->box(FL_GTK_UP_BOX);
        dl_card3->color((Fl_Color)18);

        dl_card4 = new Fl_Box(278, 177, 65, 85);
        dl_card4->box(FL_GTK_UP_BOX);
        dl_card4->color((Fl_Color)18);

        dl_card5 = new Fl_Box(350, 178, 65, 85);
        dl_card5->box(FL_GTK_UP_BOX);
        dl_card5->color((Fl_Color)18);

        dl_card6 = new Fl_Box(421, 178, 65, 85);
        dl_card6->box(FL_GTK_UP_BOX);
        dl_card6->color((Fl_Color)18);

        dl_card7 = new Fl_Box(493, 179, 65, 85);
        dl_card7->box(FL_GTK_UP_BOX);
        dl_card7->color((Fl_Color)18);

        dl_card8 = new Fl_Box(565, 180, 65, 85);
        dl_card8->box(FL_GTK_UP_BOX);
        dl_card8->color((Fl_Color)18);

        dl_card9 = new Fl_Box(637, 181, 65, 85);
        dl_card9->box(FL_GTK_UP_BOX);
        dl_card9->color((Fl_Color)18);

        dl_card10 = new Fl_Box(709, 181, 65, 85);
        dl_card10->box(FL_GTK_UP_BOX);
        dl_card10->color((Fl_Color)18);
      }
    }

    {
      player_cards = new Fl_Group(42, 522, 758, 145);
      {
        pl_card1 = new Fl_Box(65, 547, 65, 85);
        pl_card1->box(FL_GTK_UP_BOX);
        pl_card1->color((Fl_Color)18);

        pl_card2 = new Fl_Box(136, 547, 65, 85);
        pl_card2->box(FL_GTK_UP_BOX);
        pl_card2->color((Fl_Color)18);

        pl_card3 = new Fl_Box(207, 548, 65, 85);
        pl_card3->box(FL_GTK_UP_BOX);
        pl_card3->color((Fl_Color)18);

        pl_card4 = new Fl_Box(278, 549, 65, 85);
        pl_card4->box(FL_GTK_UP_BOX);
        pl_card4->color((Fl_Color)18);

        pl_card5 = new Fl_Box(350, 550, 65, 85);
        pl_card5->box(FL_GTK_UP_BOX);
        pl_card5->color((Fl_Color)18);

        pl_card6 = new Fl_Box(421, 550, 65, 85);
        pl_card6->box(FL_GTK_UP_BOX);
        pl_card6->color((Fl_Color)18);

        pl_card7 = new Fl_Box(493, 551, 65, 85);
        pl_card7->box(FL_GTK_UP_BOX);
        pl_card7->color((Fl_Color)18);

        pl_card8 = new Fl_Box(565, 552, 65, 85);
        pl_card8->box(FL_GTK_UP_BOX);
        pl_card8->color((Fl_Color)18);

        pl_card9 = new Fl_Box(637, 553, 65, 85);
        pl_card9->box(FL_GTK_UP_BOX);
        pl_card9->color((Fl_Color)18);

        pl_card10 = new Fl_Box(709, 553, 65, 85);
        pl_card10->box(FL_GTK_UP_BOX);
        pl_card10->color((Fl_Color)18);

      }
    }

    betting_box = new Fl_Box(424, 328, 125, 120);
    betting_box->box(FL_GTK_ROUND_UP_BOX);
    betting_box->color((Fl_Color)4);

    betting_amount = new Fl_Output(448, 360, 75, 54);
    betting_amount->box(FL_NO_BOX);
    betting_amount->textfont(1);
    betting_amount->textsize(34);
    betting_amount->textcolor((Fl_Color)26);

  end();
  show();

}

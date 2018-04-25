#include "table_view.h"

Table_view::Table_view() : Fl_Window(1325, 785, "Table")
{
  begin();

  card[0] = new Fl_JPEG_Image("./extra/images/cards/Gray_back.jpg");

  card[2] = new Fl_JPEG_Image("./extra/images/cards/2C.jpg");
  card[3] = new Fl_JPEG_Image("./extra/images/cards/3C.jpg");
  card[4] = new Fl_JPEG_Image("./extra/images/cards/4C.jpg");
  card[5] = new Fl_JPEG_Image("./extra/images/cards/5C.jpg");
  card[6] = new Fl_JPEG_Image("./extra/images/cards/6C.jpg");
  card[7] = new Fl_JPEG_Image("./extra/images/cards/7C.jpg");
  card[8] = new Fl_JPEG_Image("./extra/images/cards/8C.jpg");
  card[9] = new Fl_JPEG_Image("./extra/images/cards/9C.jpg");
  card[10] = new Fl_JPEG_Image("./extra/images/cards/10C.jpg");
  card[1] = new Fl_JPEG_Image("./extra/images/cards/AC.jpg");
  card[11] = new Fl_JPEG_Image("./extra/images/cards/JC.jpg");
  card[12] = new Fl_JPEG_Image("./extra/images/cards/QC.jpg");
  card[13] = new Fl_JPEG_Image("./extra/images/cards/KC.jpg");

  card[15] = new Fl_JPEG_Image("./extra/images/cards/2S.jpg");
  card[16] = new Fl_JPEG_Image("./extra/images/cards/3S.jpg");
  card[17] = new Fl_JPEG_Image("./extra/images/cards/4S.jpg");
  card[18] = new Fl_JPEG_Image("./extra/images/cards/5S.jpg");
  card[19] = new Fl_JPEG_Image("./extra/images/cards/6S.jpg");
  card[20] = new Fl_JPEG_Image("./extra/images/cards/7S.jpg");
  card[21] = new Fl_JPEG_Image("./extra/images/cards/8S.jpg");
  card[22] = new Fl_JPEG_Image("./extra/images/cards/9S.jpg");
  card[23] = new Fl_JPEG_Image("./extra/images/cards/10S.jpg");
  card[14] = new Fl_JPEG_Image("./extra/images/cards/AS.jpg");
  card[24] = new Fl_JPEG_Image("./extra/images/cards/JS.jpg");
  card[25] = new Fl_JPEG_Image("./extra/images/cards/QS.jpg");
  card[26] = new Fl_JPEG_Image("./extra/images/cards/KS.jpg");

  card[28] = new Fl_JPEG_Image("./extra/images/cards/2D.jpg");
  card[29] = new Fl_JPEG_Image("./extra/images/cards/3D.jpg");
  card[30] = new Fl_JPEG_Image("./extra/images/cards/4D.jpg");
  card[31] = new Fl_JPEG_Image("./extra/images/cards/5D.jpg");
  card[32] = new Fl_JPEG_Image("./extra/images/cards/6D.jpg");
  card[33] = new Fl_JPEG_Image("./extra/images/cards/7D.jpg");
  card[34] = new Fl_JPEG_Image("./extra/images/cards/8D.jpg");
  card[35] = new Fl_JPEG_Image("./extra/images/cards/9D.jpg");
  card[36] = new Fl_JPEG_Image("./extra/images/cards/10D.jpg");
  card[27] = new Fl_JPEG_Image("./extra/images/cards/AD.jpg");
  card[37] = new Fl_JPEG_Image("./extra/images/cards/JD.jpg");
  card[38] = new Fl_JPEG_Image("./extra/images/cards/QD.jpg");
  card[39] = new Fl_JPEG_Image("./extra/images/cards/KD.jpg");

  card[41] = new Fl_JPEG_Image("./extra/images/cards/2H.jpg");
  card[42] = new Fl_JPEG_Image("./extra/images/cards/3H.jpg");
  card[43] = new Fl_JPEG_Image("./extra/images/cards/4H.jpg");
  card[44] = new Fl_JPEG_Image("./extra/images/cards/5H.jpg");
  card[45] = new Fl_JPEG_Image("./extra/images/cards/6H.jpg");
  card[46] = new Fl_JPEG_Image("./extra/images/cards/7H.jpg");
  card[47] = new Fl_JPEG_Image("./extra/images/cards/8H.jpg");
  card[48] = new Fl_JPEG_Image("./extra/images/cards/9H.jpg");
  card[49] = new Fl_JPEG_Image("./extra/images/cards/10H.jpg");
  card[40] = new Fl_JPEG_Image("./extra/images/cards/AH.jpg");
  card[50] = new Fl_JPEG_Image("./extra/images/cards/JH.jpg");
  card[51] = new Fl_JPEG_Image("./extra/images/cards/QH.jpg");
  card[52] = new Fl_JPEG_Image("./extra/images/cards/KH.jpg");

  main_box = new Fl_Box(0, 0, 1325, 785);
  main_box->box(FL_GLEAM_THIN_UP_BOX);
  main_box->color((Fl_Color)58);

  btn_refresh = new Fl_Button(19, 23, 100, 55, "Refresh Game");
  btn_refresh->box(FL_GLEAM_THIN_UP_BOX);
  btn_refresh->color((Fl_Color)138);
  btn_refresh->labelfont(1);
  btn_refresh->labelsize(18);
  btn_refresh->labelcolor((Fl_Color)26);
  btn_refresh->align(Fl_Align(FL_ALIGN_WRAP));

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
      stand->activate();

      hit = new Fl_Button(774, 698, 105, 51, "Hit");
      hit->box(FL_GLEAM_THIN_UP_BOX);
      hit->color((Fl_Color)138);
      hit->labelfont(1);
      hit->labelsize(18);
      hit->labelcolor((Fl_Color)26);
      hit->align(Fl_Align(FL_ALIGN_WRAP));
      hit->activate();

      bet = new Fl_Button(188, 698, 105, 51, "Bet");
      bet->box(FL_GLEAM_THIN_UP_BOX);
      bet->color((Fl_Color)138);
      bet->labelfont(1);
      bet->labelsize(18);
      bet->labelcolor((Fl_Color)26);
      bet->align(Fl_Align(FL_ALIGN_WRAP));
      //bet->deactivate();

      balance = new Fl_Output(544, 705, 109, 35, "Balance ");
      balance->box(FL_GTK_ROUND_UP_BOX);
      balance->labelfont(1);
      balance->labelsize(24);
      balance->labelcolor((Fl_Color)26);
      balance->textsize(24);
      balance->textcolor(FL_GRAY0);
      balance->value("24");

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
      player_game = new Fl_Group(1015, 518, 280, 144);
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
        dl_card[0] = new Fl_Box(65, 175, 65, 99);
        dl_card[0]->box(FL_GTK_UP_BOX);
        dl_card[0]->color((Fl_Color)18);

        dl_card[1] = new Fl_Box(136, 175, 65, 99);
        dl_card[1]->box(FL_GTK_UP_BOX);
        dl_card[1]->color((Fl_Color)18);

        dl_card[2] = new Fl_Box(207, 176, 65, 99);
        dl_card[2]->box(FL_GTK_UP_BOX);
        dl_card[2]->color((Fl_Color)18);

        dl_card[3] = new Fl_Box(278, 177, 65, 99);
        dl_card[3]->box(FL_GTK_UP_BOX);
        dl_card[3]->color((Fl_Color)18);

        dl_card[4] = new Fl_Box(350, 178, 65, 99);
        dl_card[4]->box(FL_GTK_UP_BOX);
        dl_card[4]->color((Fl_Color)18);

        dl_card[5] = new Fl_Box(421, 178, 65, 99);
        dl_card[5]->box(FL_GTK_UP_BOX);
        dl_card[5]->color((Fl_Color)18);

        dl_card[6] = new Fl_Box(493, 179, 65, 99);
        dl_card[6]->box(FL_GTK_UP_BOX);
        dl_card[6]->color((Fl_Color)18);

        dl_card[7] = new Fl_Box(565, 180, 65, 99);
        dl_card[7]->box(FL_GTK_UP_BOX);
        dl_card[7]->color((Fl_Color)18);

        dl_card[8] = new Fl_Box(637, 181, 65, 99);
        dl_card[8]->box(FL_GTK_UP_BOX);
        dl_card[8]->color((Fl_Color)18);

        dl_card[9] = new Fl_Box(709, 181, 65, 99);
        dl_card[9]->box(FL_GTK_UP_BOX);
        dl_card[9]->color((Fl_Color)18);
      }
    }

    {
      player_cards = new Fl_Group(42, 522, 758, 145);
      {
        pl_card[0] = new Fl_Box(65, 547, 65, 99);
        pl_card[0]->box(FL_GTK_UP_BOX);
        pl_card[0]->color((Fl_Color)18);

        pl_card[1] = new Fl_Box(136, 547, 65, 99);
        pl_card[1]->box(FL_GTK_UP_BOX);
        pl_card[1]->color((Fl_Color)18);

        pl_card[2] = new Fl_Box(207, 548, 65, 99);
        pl_card[2]->box(FL_GTK_UP_BOX);
        pl_card[2]->color((Fl_Color)18);

        pl_card[3] = new Fl_Box(278, 549, 65, 99);
        pl_card[3]->box(FL_GTK_UP_BOX);
        pl_card[3]->color((Fl_Color)18);

        pl_card[4] = new Fl_Box(350, 550, 65, 99);
        pl_card[4]->box(FL_GTK_UP_BOX);
        pl_card[4]->color((Fl_Color)18);

        pl_card[5] = new Fl_Box(421, 550, 65, 99);
        pl_card[5]->box(FL_GTK_UP_BOX);
        pl_card[5]->color((Fl_Color)18);

        pl_card[6] = new Fl_Box(493, 551, 65, 99);
        pl_card[6]->box(FL_GTK_UP_BOX);
        pl_card[6]->color((Fl_Color)18);

        pl_card[7] = new Fl_Box(565, 552, 65, 99);
        pl_card[7]->box(FL_GTK_UP_BOX);
        pl_card[7]->color((Fl_Color)18);

        pl_card[8] = new Fl_Box(637, 553, 65, 99);
        pl_card[8]->box(FL_GTK_UP_BOX);
        pl_card[8]->color((Fl_Color)18);

        pl_card[9] = new Fl_Box(709, 553, 65, 99);
        pl_card[9]->image(card[0]);
        pl_card[9]->box(FL_GTK_UP_BOX);
        pl_card[9]->color((Fl_Color)18);

      }
    }

    betting_box = new Fl_Box(424, 328, 125, 120);
    betting_box->box(FL_GTK_ROUND_UP_BOX);
    betting_box->color((Fl_Color)4);
    betting_box->hide();

    betting_amount = new Fl_Output(448, 360, 75, 54);
    betting_amount->box(FL_NO_BOX);
    betting_amount->textfont(1);
    betting_amount->textsize(34);
    betting_amount->textcolor((Fl_Color)26);

  end();
  show();

}

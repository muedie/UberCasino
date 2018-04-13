#include "lobby_view.h"
#include "login_controller.h"
#include <string>

Lobby_view::Lobby_view() : Fl_Window(960, 635, "Lobby")
{
  begin();

  background_img = new Fl_JPEG_Image("./extra/images/2.jpg");
  main_box = new Fl_Box(0, 0, 960, 640);
  main_box->image(background_img);

  {
    scroll_window = new Fl_Scroll(18, 18, 652, 557);
    scroll_window->box(FL_GTK_DOWN_BOX);
    scroll_window->color(FL_FOREGROUND_COLOR);

    {
      dealer_info = new Fl_Group(33, 34, 589, 142);
      dealer_info->box(FL_GLEAM_THIN_UP_BOX);
      dealer_info->color((Fl_Color)36);
      dealer_info->hide();

      dealer_name = new Fl_Output(51, 54, 320, 35);
      dealer_name->box(FL_NO_BOX);
      dealer_name->textfont(1);
      dealer_name->textsize(24);
      dealer_name->textcolor((Fl_Color)26);

      dealer_id = new Fl_Output(175, 89, 127, 35, "Dealer ID      ");
      dealer_id->box(FL_NO_BOX);
      dealer_id->labelfont(1);
      dealer_id->labelsize(16);
      dealer_id->labelcolor((Fl_Color)26);
      dealer_id->textsize(16);
      dealer_id->textcolor((Fl_Color)26);

      dealer_plcount = new Fl_Output(176, 117, 127, 35, "Player Count ");
      dealer_plcount->box(FL_NO_BOX);
      dealer_plcount->labelfont(1);
      dealer_plcount->labelsize(16);
      dealer_plcount->labelcolor((Fl_Color)26);
      dealer_plcount->textsize(16);
      dealer_plcount->textcolor((Fl_Color)26);

      dealer_ssize = new Fl_Output(497, 88, 120, 35, "Shoe size     ");
      dealer_ssize->box(FL_NO_BOX);
      dealer_ssize->labelfont(1);
      dealer_ssize->labelsize(16);
      dealer_ssize->labelcolor((Fl_Color)26);
      dealer_ssize->textsize(16);
      dealer_ssize->textcolor((Fl_Color)26);

      dealer_mMbet = new Fl_Output(498, 116, 119, 35, "Min-Max bet ");
      dealer_mMbet->box(FL_NO_BOX);
      dealer_mMbet->labelfont(1);
      dealer_mMbet->labelsize(16);
      dealer_mMbet->labelcolor((Fl_Color)26);
      dealer_mMbet->textsize(16);
      dealer_mMbet->textcolor((Fl_Color)26);

      join_btn = new Fl_Button(500, 54, 95, 35, "Join");
      join_btn->box(FL_GLEAM_THIN_UP_BOX);
      join_btn->color((Fl_Color)138);
      join_btn->labelfont(1);
      join_btn->labelsize(18);
      join_btn->labelcolor((Fl_Color)26);

      dealer_info->end();
    }

    {
      dealer_info2 = new Fl_Group(33, 34+155, 589, 142);
      dealer_info2->box(FL_GLEAM_THIN_UP_BOX);
      dealer_info2->color((Fl_Color)36);
      dealer_info2->hide();

      dealer_name2 = new Fl_Output(51, 54+155, 320, 35);
      dealer_name2->box(FL_NO_BOX);
      dealer_name2->textfont(1);
      dealer_name2->textsize(24);
      dealer_name2->textcolor((Fl_Color)26);

      dealer_id2 = new Fl_Output(175, 89+155, 127, 35, "Dealer ID      ");
      dealer_id2->box(FL_NO_BOX);
      dealer_id2->labelfont(1);
      dealer_id2->labelsize(16);
      dealer_id2->labelcolor((Fl_Color)26);
      dealer_id2->textsize(16);
      dealer_id2->textcolor((Fl_Color)26);

      dealer_plcount2 = new Fl_Output(176, 117+155, 127, 35, "Player Count ");
      dealer_plcount2->box(FL_NO_BOX);
      dealer_plcount2->labelfont(1);
      dealer_plcount2->labelsize(16);
      dealer_plcount2->labelcolor((Fl_Color)26);
      dealer_plcount2->textsize(16);
      dealer_plcount2->textcolor((Fl_Color)26);

      dealer_ssize2 = new Fl_Output(497, 88+155, 120, 35, "Shoe size     ");
      dealer_ssize2->box(FL_NO_BOX);
      dealer_ssize2->labelfont(1);
      dealer_ssize2->labelsize(16);
      dealer_ssize2->labelcolor((Fl_Color)26);
      dealer_ssize2->textsize(16);
      dealer_ssize2->textcolor((Fl_Color)26);

      dealer_mMbet2 = new Fl_Output(498, 116+155, 119, 35, "Min-Max bet ");
      dealer_mMbet2->box(FL_NO_BOX);
      dealer_mMbet2->labelfont(1);
      dealer_mMbet2->labelsize(16);
      dealer_mMbet2->labelcolor((Fl_Color)26);
      dealer_mMbet2->textsize(16);
      dealer_mMbet2->textcolor((Fl_Color)26);

      join_btn2 = new Fl_Button(500, 54+155, 95, 35, "Join");
      join_btn2->box(FL_GLEAM_THIN_UP_BOX);
      join_btn2->color((Fl_Color)138);
      join_btn2->labelfont(1);
      join_btn2->labelsize(18);
      join_btn2->labelcolor((Fl_Color)26);

      dealer_info2->end();
    }

    {
      dealer_info3 = new Fl_Group(33, 34+310, 589, 142);
      dealer_info3->box(FL_GLEAM_THIN_UP_BOX);
      dealer_info3->color((Fl_Color)36);
      dealer_info3->hide();

      dealer_name3 = new Fl_Output(51, 54+310, 320, 35);
      dealer_name3->box(FL_NO_BOX);
      dealer_name3->textfont(1);
      dealer_name3->textsize(24);
      dealer_name3->textcolor((Fl_Color)26);

      dealer_id3 = new Fl_Output(175, 89+310, 127, 35, "Dealer ID      ");
      dealer_id3->box(FL_NO_BOX);
      dealer_id3->labelfont(1);
      dealer_id3->labelsize(16);
      dealer_id3->labelcolor((Fl_Color)26);
      dealer_id3->textsize(16);
      dealer_id3->textcolor((Fl_Color)26);

      dealer_plcount3 = new Fl_Output(176, 117+310, 127, 35, "Player Count ");
      dealer_plcount3->box(FL_NO_BOX);
      dealer_plcount3->labelfont(1);
      dealer_plcount3->labelsize(16);
      dealer_plcount3->labelcolor((Fl_Color)26);
      dealer_plcount3->textsize(16);
      dealer_plcount3->textcolor((Fl_Color)26);

      dealer_ssize3 = new Fl_Output(497, 88+310, 120, 35, "Shoe size     ");
      dealer_ssize3->box(FL_NO_BOX);
      dealer_ssize3->labelfont(1);
      dealer_ssize3->labelsize(16);
      dealer_ssize3->labelcolor((Fl_Color)26);
      dealer_ssize3->textsize(16);
      dealer_ssize3->textcolor((Fl_Color)26);

      dealer_mMbet3 = new Fl_Output(498, 116+310, 119, 35, "Min-Max bet ");
      dealer_mMbet3->box(FL_NO_BOX);
      dealer_mMbet3->labelfont(1);
      dealer_mMbet3->labelsize(16);
      dealer_mMbet3->labelcolor((Fl_Color)26);
      dealer_mMbet3->textsize(16);
      dealer_mMbet3->textcolor((Fl_Color)26);

      join_btn3 = new Fl_Button(500, 54+310, 95, 35, "Join");
      join_btn3->box(FL_GLEAM_THIN_UP_BOX);
      join_btn3->color((Fl_Color)138);
      join_btn3->labelfont(1);
      join_btn3->labelsize(18);
      join_btn3->labelcolor((Fl_Color)26);

      dealer_info3->end();
    }

    {
      dealer_info4 = new Fl_Group(33, 34+465, 589, 142);
      dealer_info4->box(FL_GLEAM_THIN_UP_BOX);
      dealer_info4->color((Fl_Color)36);
      dealer_info4->hide();

      dealer_name4 = new Fl_Output(51, 54+465, 320, 35);
      dealer_name4->box(FL_NO_BOX);
      dealer_name4->textfont(1);
      dealer_name4->textsize(24);
      dealer_name4->textcolor((Fl_Color)26);

      dealer_id4 = new Fl_Output(175, 89+465, 127, 35, "Dealer ID      ");
      dealer_id4->box(FL_NO_BOX);
      dealer_id4->labelfont(1);
      dealer_id4->labelsize(16);
      dealer_id4->labelcolor((Fl_Color)26);
      dealer_id4->textsize(16);
      dealer_id4->textcolor((Fl_Color)26);

      dealer_plcount4 = new Fl_Output(176, 117+465, 127, 35, "Player Count ");
      dealer_plcount4->box(FL_NO_BOX);
      dealer_plcount4->labelfont(1);
      dealer_plcount4->labelsize(16);
      dealer_plcount4->labelcolor((Fl_Color)26);
      dealer_plcount4->textsize(16);
      dealer_plcount4->textcolor((Fl_Color)26);

      dealer_ssize4 = new Fl_Output(497, 88+465, 120, 35, "Shoe size     ");
      dealer_ssize4->box(FL_NO_BOX);
      dealer_ssize4->labelfont(1);
      dealer_ssize4->labelsize(16);
      dealer_ssize4->labelcolor((Fl_Color)26);
      dealer_ssize4->textsize(16);
      dealer_ssize4->textcolor((Fl_Color)26);

      dealer_mMbet4 = new Fl_Output(498, 116+465, 119, 35, "Min-Max bet ");
      dealer_mMbet4->box(FL_NO_BOX);
      dealer_mMbet4->labelfont(1);
      dealer_mMbet4->labelsize(16);
      dealer_mMbet4->labelcolor((Fl_Color)26);
      dealer_mMbet4->textsize(16);
      dealer_mMbet4->textcolor((Fl_Color)26);

      join_btn4 = new Fl_Button(500, 54+465, 95, 35, "Join");
      join_btn4->box(FL_GLEAM_THIN_UP_BOX);
      join_btn4->color((Fl_Color)138);
      join_btn4->labelfont(1);
      join_btn4->labelsize(18);
      join_btn4->labelcolor((Fl_Color)26);

      dealer_info4->end();
    }


    scroll_window->end();
  }

  refresh_btn = new Fl_Button(120, 585, 155, 40, "Refresh");
  refresh_btn->box(FL_GLEAM_THIN_UP_BOX);
  refresh_btn->color((Fl_Color)138);
  refresh_btn->labelfont(1);
  refresh_btn->labelsize(18);
  refresh_btn->labelcolor((Fl_Color)26);

  logout_btn = new Fl_Button(400, 585, 155, 40, "Logout");
  logout_btn->box(FL_GLEAM_THIN_UP_BOX);
  logout_btn->color((Fl_Color)138);
  logout_btn->labelfont(1);
  logout_btn->labelsize(18);
  logout_btn->labelcolor((Fl_Color)26);

  side_box = new Fl_Box(687, 20, 255, 595);
  side_box->box(FL_GTK_DOWN_BOX);
  side_box->color(FL_FOREGROUND_COLOR);

  {
    player_info = new Fl_Group(695, 43, 240, 268);
    player_info ->box(FL_GLEAM_THIN_UP_BOX);
    player_info ->color((Fl_Color)36);

    player_title = new Fl_Text_Display(729, 95, 155, 0, "Player Info");
    player_title->box(FL_NO_BOX);
    player_title->labelfont(1);
    player_title->labelsize(24);
    player_title->labelcolor((Fl_Color)26);
    player_title->align(Fl_Align(129));

    player_name = new Fl_Output(818, 105, 102, 29, "Name          ");
    player_name->box(FL_NO_BOX);
    player_name->labelfont(1);
    player_name->labelsize(16);
    player_name->labelcolor((Fl_Color)26);
    player_name->textsize(16);
    player_name->textcolor((Fl_Color)26);

    player_id = new Fl_Output(818, 130, 102, 30, "Player ID     ");
    player_id->box(FL_NO_BOX);
    player_id->labelfont(1);
    player_id->labelsize(16);
    player_id->labelcolor((Fl_Color)26);
    player_id->textsize(16);
    player_id->textcolor((Fl_Color)26);

    player_balance = new Fl_Output(819, 157, 104, 29, "Balance       ");
    player_balance->box(FL_NO_BOX);
    player_balance->labelfont(1);
    player_balance->labelsize(16);
    player_balance->labelcolor((Fl_Color)26);
    player_balance->textsize(16);
    player_balance->textcolor((Fl_Color)26);

    player_games_played = new Fl_Output(821, 183, 94, 28, "Total Games");
    player_games_played->box(FL_NO_BOX);
    player_games_played->labelfont(1);
    player_games_played->labelsize(16);
    player_games_played->labelcolor((Fl_Color)26);
    player_games_played->textsize(16);
    player_games_played->textcolor((Fl_Color)26);

    player_hands_won = new Fl_Output(819, 208, 100, 29, "Hands won  ");
    player_hands_won->box(FL_NO_BOX);
    player_hands_won->labelfont(1);
    player_hands_won->labelsize(16);
    player_hands_won->labelcolor((Fl_Color)26);
    player_hands_won->textsize(16);
    player_hands_won->textcolor((Fl_Color)26);

    player_info->end();
  }

  {
    play_style = new Fl_Group(696, 333, 239, 256);
    play_style->box(FL_GLEAM_THIN_UP_BOX);
    play_style->color((Fl_Color)36);

    play_title = new Fl_Text_Display(704, 386, 213, 0, "Play style");
    play_title->box(FL_NO_BOX);
    play_title->labelfont(1);
    play_title->labelsize(24);
    play_title->labelcolor((Fl_Color)26);
    play_title->align(Fl_Align(129));

    manual = new Fl_Round_Button(711, 396, 25, 25, " Manual");
    manual->down_box(FL_ROUND_DOWN_BOX);
    manual->labelfont(1);
    manual->labelsize(16);
    manual->labelcolor((Fl_Color)26);
    manual->type(FL_RADIO_BUTTON);
    manual->setonly();

    basic = new Fl_Round_Button(711, 420, 25, 25, " Basic");
    basic->down_box(FL_ROUND_DOWN_BOX);
    basic->labelfont(1);
    basic->labelsize(16);
    basic->labelcolor((Fl_Color)26);
    basic->type(FL_RADIO_BUTTON);

    aggressive = new Fl_Round_Button(711, 443, 25, 25, " Aggressive");
    aggressive->down_box(FL_ROUND_DOWN_BOX);
    aggressive->labelfont(1);
    aggressive->labelsize(16);
    aggressive->labelcolor((Fl_Color)26);
    aggressive->type(FL_RADIO_BUTTON);

    counting = new Fl_Round_Button(711, 466, 25, 25, " Counting");
    counting->down_box(FL_ROUND_DOWN_BOX);
    counting->labelfont(1);
    counting->labelsize(16);
    counting->labelcolor((Fl_Color)26);
    counting->type(FL_RADIO_BUTTON);

    conservative = new Fl_Round_Button(711, 489, 25, 25, " Conservative");
    conservative->down_box(FL_ROUND_DOWN_BOX);
    conservative->labelfont(1);
    conservative->labelsize(16);
    conservative->labelcolor((Fl_Color)26);
    conservative->type(FL_RADIO_BUTTON);

    play_style->end();
  }

  end();
  show();

}

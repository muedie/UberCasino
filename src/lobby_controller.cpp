#include "lobby_controller.h"
#include "login_controller.h"
#include "table_controller.h"

#include <functional>
#include <cstdlib>

void timer_cb(void *v)        //fltk timer function to repeat timer every 1 second... Controls the FPS for table window
{
  Fl::repeat_timeout(double(1.0)/1,timer_cb);
}

Lobby_controller::Lobby_controller(player& p) : Lobby_view() , _p{p} {
  Fl::remove_timeout(timer_cb);         //removes the previous timeout if left game from table window
  player_name->value(_p.getName().c_str());
  float bal = _p.getBalance();
  int b = int(bal + 0.5);                 //just to remove decimal places
  player_balance->value(std::to_string(b).c_str());
  player_id->value(_p.getPlayerID().c_str());
  player_games_played->value(std::to_string(_p.get_hands_played()).c_str());        //player game record
  player_hands_won->value(std::to_string(_p.get_hands_won()).c_str());

  manual->when(FL_WHEN_CHANGED);
  basic->when(FL_WHEN_CHANGED);
  aggressive->when(FL_WHEN_CHANGED);
  counting->when(FL_WHEN_CHANGED);
  conservative->when(FL_WHEN_CHANGED);

  manual->callback(ClickedRound1, (void*) this);        //radio button callback.. sets play style
  basic->callback(ClickedRound2, (void*) this);
  aggressive->callback(ClickedRound3,(void*) this);
  counting->callback(ClickedRound4, (void*) this);
  conservative->callback(ClickedRound5, (void*) this);

  refresh_btn->callback(ClickedRefresh, this);        //refresh button to check the available dealers
  logout_btn->callback(ClickedLogout, this);

  join_btn->callback(ClickedJoin1, (void*)this);          //different join call back button for different dealers
  join_btn2->callback(ClickedJoin2, (void*)this);
  join_btn3->callback(ClickedJoin3, (void*)this);
  join_btn4->callback(ClickedJoin4, (void*)this);
}

void Lobby_controller::ClickedLogout(Fl_Widget* w, void* data)
{
  ((Lobby_controller*)data)->ClickedLogout_i();
}

void Lobby_controller::ClickedRefresh(Fl_Widget* w, void* data)
{
  ((Lobby_controller*)data)->ClickedRefresh_i();
}

void Lobby_controller::ClickedJoin1(Fl_Widget* w, void* data)
{
  ((Lobby_controller*)data)->ClickedJoin1_i();
}

void Lobby_controller::ClickedJoin2(Fl_Widget* w, void* data)
{
  ((Lobby_controller*)data)->ClickedJoin2_i();
}

void Lobby_controller::ClickedJoin3(Fl_Widget* w, void* data)
{
  ((Lobby_controller*)data)->ClickedJoin3_i();
}

void Lobby_controller::ClickedJoin4(Fl_Widget* w, void* data)
{
  ((Lobby_controller*)data)->ClickedJoin4_i();
}

void Lobby_controller::ClickedRound1(Fl_Widget* w, void* data)
{
  ((Lobby_controller*)data)->ClickedRound1_i();
}

void Lobby_controller::ClickedRound1_i()
{
  _p.set_play_style(1);

}

void Lobby_controller::ClickedRound2(Fl_Widget* w, void* data)
{
  ((Lobby_controller*)data)->ClickedRound2_i();
}

void Lobby_controller::ClickedRound2_i()
{
  _p.set_play_style(2);

}

void Lobby_controller::ClickedRound3(Fl_Widget* w, void* data)
{
  ((Lobby_controller*)data)->ClickedRound3_i();
}

void Lobby_controller::ClickedRound3_i()
{
  _p.set_play_style(3);

}

void Lobby_controller::ClickedRound4(Fl_Widget* w, void* data)
{
  ((Lobby_controller*)data)->ClickedRound4_i();
}

void Lobby_controller::ClickedRound4_i()
{
  _p.set_play_style(4);

}

void Lobby_controller::ClickedRound5(Fl_Widget* w, void* data)
{
  ((Lobby_controller*)data)->ClickedRound5_i();
}

void Lobby_controller::ClickedRound5_i()
{
  _p.set_play_style(5);
}


//Implement your model here in these call back function.

void Lobby_controller::ClickedRefresh_i()
{
    vector<Dealer> v = _p.getDealer_list();         //loads the dealer from vector of dealers stored when dealer data received
    boost::uuids::uuid uuid;
    string s1, s2;
    switch (v.size()) {             //the no. of dealers shows the no. of dealer info boxes
      case 4:
      dealer_info4->show();
      s1 = v[3].name;
      memcpy ( v[3].uid, &uuid, 16 );
      s2 = boost::uuids::to_string(uuid);      //convert boost uuid to string so that it can be displayed on screen
      dealer_name4->value(s1.c_str());
      dealer_id4->value(s2.c_str());

      case 3:
      dealer_info3->show();
      s1 = v[2].name;
      memcpy ( v[2].uid, &uuid, 16 );
      s2 = boost::uuids::to_string(uuid);
      dealer_name3->value(s1.c_str());
      dealer_id3->value(s2.c_str());

      case 2:
      dealer_info2->show();
      s1 = v[1].name;
      memcpy ( v[1].uid, &uuid, 16 );
      s2 = boost::uuids::to_string(uuid);
      dealer_name2->value(s1.c_str());
      dealer_id2->value(s2.c_str());

      case 1:
      s1 = v[0].name;
      memcpy ( v[0].uid, &uuid, 16 );
      s2 = boost::uuids::to_string(uuid);
      dealer_name->value(s1.c_str());
      dealer_id->value(s2.c_str());
      dealer_info->show();
      default: break;
    }
}

void Lobby_controller::ClickedLogout_i()
{
  hide();
  _p = player();
  Login_controller win(_p);
  Fl::run();
}

void Lobby_controller::ClickedJoin1_i()
{
  hide();
  _p.setDealerIDX(0);             //set the dealer id in player data so as to join to specific dealer
  Table_controller win(_p);
  Fl::add_timeout(0.1,timer_cb);      //fltk timer to control FPS for non flickering window
  Fl::run();
}

void Lobby_controller::ClickedJoin2_i()       //2nd dealer info box call back
{
  hide();
  _p.setDealerIDX(1);
  Table_controller win(_p);
  Fl::add_timeout(0.1,timer_cb);
  Fl::run();
}

void Lobby_controller::ClickedJoin3_i()
{
  hide();
  _p.setDealerIDX(2);
  Table_controller win(_p);
  Fl::add_timeout(0.1,timer_cb);
  Fl::run();
}

void Lobby_controller::ClickedJoin4_i()
{
  hide();
  _p.setDealerIDX(3);
  Table_controller win(_p);
  Fl::add_timeout(0.1,timer_cb,&win);
  Fl::run();
}

#include "lobby_controller.h"
#include "login_controller.h"
#include "table_controller.h"

#include <functional>
#include <cstdlib>

#include <boost/thread.hpp>


void timr_cb(void *v)
{
  Fl::repeat_timeout(double(1.0)/15, timr_cb);
}

void lob_thread ( int seconds, std::function <void(void)> callback)
{
  while(1)
  {
    boost::this_thread::sleep_for(boost::chrono::seconds(seconds));
    callback ();
  }
}




Lobby_controller::Lobby_controller(player& p) : Lobby_view() , _p{p} {
  lobby_thread = new boost::thread ( lob_thread , 0.1 , std::bind ( &Lobby_controller::ClickedRefresh_i, this) );
  player_name->value(_p.getName().c_str());
  float bal = _p.getBalance();
  int b = int(bal + 0.5);
  player_balance->value(std::to_string(b).c_str());
  player_id->value(_p.getPlayerID().c_str());
  player_games_played->value(std::to_string(_p.get_hands_played()).c_str());
  player_hands_won->value(std::to_string(_p.get_hands_won()).c_str());

  manual->when(FL_WHEN_CHANGED);
  basic->when(FL_WHEN_CHANGED);
  aggressive->when(FL_WHEN_CHANGED);
  counting->when(FL_WHEN_CHANGED);
  conservative->when(FL_WHEN_CHANGED);

  manual->callback(ClickedRound1, (void*) this);
  basic->callback(ClickedRound2, (void*) this);
  aggressive->callback(ClickedRound3,(void*) this);
  counting->callback(ClickedRound4, (void*) this);
  conservative->callback(ClickedRound5, (void*) this);

  logout_btn->callback(ClickedLogout, this);

  join_btn->callback(ClickedJoin1, (void*)this);
  join_btn2->callback(ClickedJoin2, (void*)this);
  join_btn3->callback(ClickedJoin3, (void*)this);
  join_btn4->callback(ClickedJoin4, (void*)this);
}

void Lobby_controller::ClickedLogout(Fl_Widget* w, void* data)
{
  ((Lobby_controller*)data)->ClickedLogout_i();
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
  Fl::lock();
    vector<Dealer> v = _p.getDealer_list();
    std::ostringstream st;
    string s1, s2;
    switch (v.size()) {
      case 4:
      dealer_info4->show();
      s1 = v[3].name;
      st << v[3].uid;
      s2 = st.str();
      dealer_name4->value(s1.c_str());
      dealer_id4->value(s2.c_str());

      case 3:
      dealer_info3->show();
      s1 = v[2].name;
      st << v[2].uid;
      s2 = st.str();
      dealer_name3->value(s1.c_str());
      dealer_id3->value(s2.c_str());

      case 2:
      dealer_info2->show();
      s1 = v[1].name;
      st << v[1].uid;
      s2 = st.str();
      dealer_name2->value(s1.c_str());
      dealer_id2->value(s2.c_str());

      case 1:
      s1 = v[0].name;
      st << v[0].uid;
      s2 = st.str();
      dealer_name->value(s1.c_str());
      dealer_id->value(s2.c_str());
      dealer_info->show();
      default: break;
    }
    Fl::unlock();
}

void Lobby_controller::ClickedLogout_i()
{
  hide();
  lobby_thread->interrupt ();
  delete lobby_thread;
  lobby_thread = NULL;
  _p = player();
  Login_controller win(_p);
  Fl::run();
}

void Lobby_controller::ClickedJoin1_i()
{
  hide();
  lobby_thread->interrupt ();
  delete lobby_thread;
  lobby_thread = NULL;
  _p.setDealerIDX(0);
  Table_controller win(_p);
  Fl::add_timeout(0.1,timr_cb);
  Fl::run();
}

void Lobby_controller::ClickedJoin2_i()
{
  hide();
  lobby_thread->interrupt ();
  delete lobby_thread;
  lobby_thread = NULL;
  _p.setDealerIDX(1);
  Table_controller win(_p);
  Fl::add_timeout(0.1,timr_cb);
  Fl::run();
}

void Lobby_controller::ClickedJoin3_i()
{
  hide();
  lobby_thread->interrupt ();
  delete lobby_thread;
  lobby_thread = NULL;
  _p.setDealerIDX(2);
  Table_controller win(_p);
  Fl::add_timeout(0.1,timr_cb);
  Fl::run();
}

void Lobby_controller::ClickedJoin4_i()
{
  hide();
  lobby_thread->interrupt ();
  delete lobby_thread;
  lobby_thread = NULL;
  _p.setDealerIDX(3);
  Table_controller win(_p);
  Fl::add_timeout(0.1,timr_cb);
  Fl::run();
}

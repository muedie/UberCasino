#ifndef PLAYER_MODEL_H
#define PLAYER_MODEL_H 2018

#include <string>

enum player_action_t {idle, hitting, standing, splitting, doubling};

class Player {
    public:
        Player();
        std::string getName();
        std::string getUUID();
        float getBalance();
        void setName(std::string name);
        void setUUID(std::string uuid);

    private:
        std::string _uuid;
        std::string _name;
        float _balance;
        player_action_t A;
};

#endif

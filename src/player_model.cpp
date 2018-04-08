#include "../include/player_model.h"

Player::Player() {
    _uuid = "00";
    _name = "Player1";
    _balance = 500;
}

std::string Player::getName() {
    return _name;
}

std::string Player::getUUID() {
    return _uuid;
}

void Player::setName(std::string name) {
    _name = name;
}

void Player::setUUID(std::string uuid) {
    _uuid = uuid;
}

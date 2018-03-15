#include "player_model.h"

Player::Player(std::string uuid, std::string name) {
    _uuid = uuid;
    _name = name;
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

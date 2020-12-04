#include <stdexcept>

#include "Player.h"

Player::Player() {
    name = "";
    winner = false;
    tile_index = 0;
}

Player::Player(std::string _name) {
    name = _name;
    winner = false;
    tile_index = 0;
}

int Player::get_tile_index() {
    return tile_index;
}

std::string Player::get_name() {
    return name;
}

bool Player::won() {
    if (winner) return true;
    
    return false;
}

Player& Player::operator+=(int _tile_index) {
    tile_index += _tile_index;

    // tile index minimum value is always 1
    if (tile_index < 0) tile_index = 0;

    // player wins if they reach the final tile which is the 30th
    if (tile_index >= MAX_TILE_INDEX - 1) winner = true;

    return *this;
}

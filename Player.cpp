//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "Player.h"

Color Player::get_side() const {
    return side;
}

void Player::set_side(Color side) {
    this->side = side;
}

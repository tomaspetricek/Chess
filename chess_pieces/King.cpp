//
// Created by Tomáš Petříček on 07.07.2021.
//

#include "King.h"

King::King(const Position &pos, Player *owner, Color color)
        : ChessPiece{pos, owner, color} {}

bool King::valid_move(const Position &pos) {
    return false;
}


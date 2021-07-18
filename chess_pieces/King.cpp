//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "King.h"

King::King(const Position &pos, Color color)
        : ChessPiece{pos, color, false, def_id} {}

bool King::valid_move(const Position &pos) {
    return false;
}

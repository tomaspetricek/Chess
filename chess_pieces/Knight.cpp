//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "Knight.h"

Knight::Knight(const Position &pos, Player *owner, Color color)
        : ChessPiece{pos, owner, color, def_jumps_over, def_id} {}

bool Knight::valid_move(const Position &pos) {
    return false;
}
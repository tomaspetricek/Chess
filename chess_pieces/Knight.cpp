//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "Knight.h"

Knight::Knight(const Position &pos, Player *owner, Color color)
        : ChessPiece{pos, owner, color} {}

bool Knight::valid_move(const Position &pos) {
    return false;
}
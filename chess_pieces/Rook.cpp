//
// Created by Tomáš Petříček on 07.07.2021.
//

#include "Rook.h"

Rook::Rook(const Position &pos, Player *owner, Color color)
        : ChessPiece{pos, owner, color} {}

bool Rook::valid_move(const Position &pos) {
    return (go_vertical_direction(this->pos, pos) || go_horizontal_direction(this->pos, pos));
}


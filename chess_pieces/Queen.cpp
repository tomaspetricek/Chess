//
// Created by Tomáš Petříček on 07.07.2021.
//

#include "Queen.h"

Queen::Queen(const Position &pos, Player *owner, Color color)
        : ChessPiece{pos, owner, color} {}

bool Queen::valid_move(const Position &pos) {
    return (go_vertical_direction(this->pos, pos) ||
            go_horizontal_direction(this->pos, pos) ||
            go_diagonal_direction(this->pos, pos));
}


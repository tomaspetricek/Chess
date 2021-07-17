//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "Bishop.h"

bool Bishop::valid_move(const Position &pos) {
    return go_diagonal_direction(this->pos, pos);
}

Bishop::Bishop(const Position &pos, Player *owner, Color color)
        : ChessPiece(pos, owner, color) {}
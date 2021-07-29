//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "Rook.h"

Rook::Rook(const Position &pos, Color color)
        : ChessPiece{pos, color, false, def_id} {}

bool Rook::valid_move(const Position &pos) {
    return (go_vertical_direction(this->pos, pos) || go_horizontal_direction(this->pos, pos));
}

void Rook::print(std::ostream &os) const {
    ChessPiece::print(os);
}

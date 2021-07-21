//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "Pawn.h"


Pawn::Pawn(const Position &pos, Color color)
        : ChessPiece{pos, color, false, def_id} {}

bool Pawn::valid_move(const Position &pos) {
    int x_diff = this->pos.get_x() - pos.get_x();
    int y_diff = this->pos.get_y() - pos.get_y();
    return (x_diff == 1 && y_diff == 0);
}

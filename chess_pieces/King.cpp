//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "King.h"
#include <cmath>

King::King(const Position &pos, Color color)
        : ChessPiece{pos, color, false, def_id} {}

bool King::valid_move(const Position &pos) {
    int x_abs_diff = std::abs(this->pos.get_x() - pos.get_x());
    int y_abs_diff = std::abs(this->pos.get_y() - pos.get_y());
    return (x_abs_diff == 1 && y_abs_diff == 1) || (x_abs_diff == 0 && y_abs_diff == 1) || (x_abs_diff == 1 && y_abs_diff == 0);
}

void King::print(std::ostream &os) const {
    ChessPiece::print(os);
}

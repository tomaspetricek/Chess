//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "Knight.h"
#include <cmath>

Knight::Knight(const Position &pos, Color color)
        : ChessPiece{pos, color, def_jumps_over, def_id} {}

bool Knight::valid_move(const Position &pos) {
    int x_abs_diff = std::abs(this->pos.get_x() - pos.get_x());
    int y_abs_diff = std::abs(this->pos.get_x() - pos.get_x());
    return (x_abs_diff == 1 && y_abs_diff == 2) || (x_abs_diff == 2 && y_abs_diff == 1);
}
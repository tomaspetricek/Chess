//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "Queen.h"


Queen::Queen(const Position &pos, Player *owner, Color color)
        : ChessPiece{pos, owner, color, false, def_id} {}

bool Queen::valid_move(const Position &pos) {
    return (go_vertical_direction(this->pos, pos) ||
            go_horizontal_direction(this->pos, pos) ||
            go_diagonal_direction(this->pos, pos));
}

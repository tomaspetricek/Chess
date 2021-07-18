//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "Pawn.h"


Pawn::Pawn(const Position &pos, Color color)
        : ChessPiece{pos, color, false, def_id} {}

bool Pawn::valid_move(const Position &pos) {
    return false;
}

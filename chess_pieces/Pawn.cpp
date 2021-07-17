//
// Created by Tomáš Petříček on 07.07.2021.
//

#include "Pawn.h"


Pawn::Pawn(const Position &pos, Player *owner, Color color)
        : ChessPiece{pos, owner, color} {}

bool Pawn::valid_move(const Position &pos) {
    return false;
}


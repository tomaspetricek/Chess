//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "ChessPiece.h"

ChessPiece::ChessPiece(const Position &pos, Player *owner, Color color, bool jumps_over)
        : pos{pos}, owner{owner}, color{color}, has_moved{false}, jumps_over{jumps_over} {}

Player *ChessPiece::get_owner() const {
    return owner;
}

void ChessPiece::set_owner(Player *owner) {
    ChessPiece::owner = owner;
}

Color ChessPiece::get_color() const {
    return color;
}

void ChessPiece::set_color(Color color) {
    ChessPiece::color = color;
}

bool ChessPiece::get_has_moved() const {
    return has_moved;
}

void ChessPiece::set_has_moved(bool has_moved) {
    ChessPiece::has_moved = has_moved;
}

const Position &ChessPiece::get_pos() const {
    return pos;
}

void ChessPiece::set_pos(const Position &pos) {
    ChessPiece::pos = pos;
}

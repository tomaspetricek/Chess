//
// Created by Tomáš Petříček on 07.07.2021.
//

#include "ChessPiece.h"

ChessPiece::ChessPiece(const Position &pos, Player *owner, Color color)
        : pos{pos}, owner{owner}, color{color}, jumps_over{jumps_over}, has_moved{false} {}

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

bool ChessPiece::is_has_moved() const {
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

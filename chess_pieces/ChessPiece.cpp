//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "ChessPiece.h"

ChessPiece::ChessPiece(const Position &pos, Color color, bool jumps_over, int id)
        : pos{pos}, color{color}, has_moved{false}, jumps_over{jumps_over}, id{id} {}


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

int ChessPiece::get_id() const {
    return id;
}

void ChessPiece::set_id(int id) {
    ChessPiece::id = id;
}

void ChessPiece::print(std::ostream &os) const {

}

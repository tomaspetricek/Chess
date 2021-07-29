//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "Field.h"

#include <utility>

Field::Field(Position pos, Color color) : pos{pos}, color{color}{}

Color Field::get_color() const {
    return color;
}

void Field::set_color(Color color) {
    Field::color = color;
}

bool Field::is_empty() const{
    return (piece_ptr == nullptr);
}

const Position &Field::get_pos() const {
    return pos;
}

const std::shared_ptr<ChessPiece> &Field::get_piece_ptr() const {
    return piece_ptr;
}

void Field::set_piece_ptr(const std::shared_ptr<ChessPiece> &piece_ptr) {
    Field::piece_ptr = piece_ptr;
}

void Field::reset_piece_ptr() {
    piece_ptr.reset();
}


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

const std::unique_ptr<ChessPiece> &Field::get_piece_ptr() const{
    return piece_ptr;
}

void Field::set_piece_ptr(std::unique_ptr<ChessPiece> piece_ptr) {
    Field::piece_ptr = std::move(piece_ptr);
}

std::unique_ptr<ChessPiece> &Field::move_piece_ptr() {
    return piece_ptr;
}

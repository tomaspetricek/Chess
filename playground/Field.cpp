//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "Field.h"

Field::Field(Color color) : color(color) {}

ChessPiece *Field::get_chess_piece() const {
    return chess_piece;
}

void Field::set_chess_piece(ChessPiece *chess_piece) {
    Field::chess_piece = chess_piece;
}

Color Field::get_color() const {
    return color;
}

void Field::set_color(Color color) {
    Field::color = color;
}

void Field::add_chess_piece(ChessPiece *chess_piece) {
    this->chess_piece = chess_piece;
}

void Field::remove_chess_piece() {
    this->chess_piece = nullptr;
}

bool Field::is_empty() const{
    return (chess_piece == nullptr);
}

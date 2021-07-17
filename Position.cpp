//
// Created by Tomáš Petříček on 07.07.2021.
//

#include "Position.h"

int Position::get_x() const {
    return x;
}

void Position::set_x(int x) {
    Position::x = x;
}

int Position::get_y() const {
    return y;
}

void Position::set_y(int y) {
    Position::y = y;
}

Position::Position(int x, int y) : x{x}, y{y} {}

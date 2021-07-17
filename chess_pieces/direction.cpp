//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "direction.h"

bool go_diagonal_direction(const Position &a, const Position &b){
    int y_diff = a.get_y() - b.get_y();
    int x_diff = a.get_x() - b.get_x();
    return std::abs(x_diff) == std::abs(y_diff);
}

bool go_horizontal_direction(const Position &a, const Position &b){
    return a.get_x() == b.get_x();
}

bool go_vertical_direction(const Position &a, const Position &b){
    return a.get_y() == b.get_y();
}

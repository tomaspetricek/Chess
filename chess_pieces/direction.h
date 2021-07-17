//
// Created by Tomáš Petříček on 09.07.2021.
//

#ifndef MINIPROJECTS_DIRECTION_H
#define MINIPROJECTS_DIRECTION_H

#include "../Position.h"
#include <cmath>

bool go_horizontal_direction(const Position &a, const Position &b);

bool go_vertical_direction(const Position &a, const Position &b);

bool go_diagonal_direction(const Position &a, const Position &b);
#endif //MINIPROJECTS_DIRECTION_H

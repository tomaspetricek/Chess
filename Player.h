//
// Created by Tomáš Petříček on 17.07.2021.
//

#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H

#include "enums.h"

class Player {
    Color side;
public:
    Color get_side() const;

    void set_side(Color side);
};


#endif //CHESS_PLAYER_H

//
// Created by Tomáš Petříček on 17.07.2021.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H

#include "ChessPiece.h"


class Knight: public ChessPiece {
public:
    static const bool jumps_over = true;

    explicit Knight(const Position &pos = {0, 0}, Player *owner = nullptr, Color color = Black);

    ~Knight() override = default;

    bool valid_move(const Position &pos) override;
};


#endif //CHESS_KNIGHT_H

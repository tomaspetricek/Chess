//
// Created by Tomáš Petříček on 17.07.2021.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "ChessPiece.h"


class Rook: public ChessPiece {
public:
    explicit Rook(const Position &pos = {0, 0}, Player *owner = nullptr, Color color = Black);

    ~Rook() override = default;

    bool valid_move(const Position &pos) override;
};


#endif //CHESS_ROOK_H

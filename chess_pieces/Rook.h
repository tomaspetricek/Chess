//
// Created by Tomáš Petříček on 07.07.2021.
//

#ifndef MINIPROJECTS_ROOK_H
#define MINIPROJECTS_ROOK_H

#include "ChessPiece.h"

class Rook: public ChessPiece {
public:
    explicit Rook(const Position &pos = {0, 0}, Player *owner = nullptr, Color color = Black);

    ~Rook() override = default;

    bool valid_move(const Position &pos) override;
};

#endif //MINIPROJECTS_ROOK_H

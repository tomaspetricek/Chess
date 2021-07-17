//
// Created by Tomáš Petříček on 07.07.2021.
//

#ifndef MINIPROJECTS_PAWN_H
#define MINIPROJECTS_PAWN_H

#include "ChessPiece.h"

class Pawn : public ChessPiece {
public:
    explicit Pawn(const Position &pos = {0, 0}, Player *owner = nullptr, Color color = Black);

    ~Pawn() override = default;

    bool valid_move(const Position &pos) override;
};

#endif //MINIPROJECTS_PAWN_H

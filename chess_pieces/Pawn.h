//
// Created by Tomáš Petříček on 17.07.2021.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "ChessPiece.h"


class Pawn : public ChessPiece {
public:
    explicit Pawn(const Position &pos = {0, 0}, Player *owner = nullptr, Color color = Black);

    ~Pawn() override = default;

    bool valid_move(const Position &pos) override;
};


#endif //CHESS_PAWN_H

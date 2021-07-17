//
// Created by Tomáš Petříček on 07.07.2021.
//

#ifndef MINIPROJECTS_QUEEN_H
#define MINIPROJECTS_QUEEN_H

#include "ChessPiece.h"

class Queen: public ChessPiece {
public:
    explicit Queen(const Position &pos = {0, 0}, Player *owner = nullptr, Color color = Black);

    ~Queen() override = default;

    bool valid_move(const Position &pos) override;
};


#endif //MINIPROJECTS_QUEEN_H

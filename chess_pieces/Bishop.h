//
// Created by Tomáš Petříček on 07.07.2021.
//

#ifndef MINIPROJECTS_BISHOP_H
#define MINIPROJECTS_BISHOP_H

#include "ChessPiece.h"
#include "direction.h"

class Bishop : public ChessPiece {
public:
    explicit Bishop(const Position &pos = {0, 0}, Player *owner = nullptr, Color color = Black);

    ~Bishop() override = default;

    bool valid_move(const Position &pos) override;
};


#endif //MINIPROJECTS_BISHOP_H

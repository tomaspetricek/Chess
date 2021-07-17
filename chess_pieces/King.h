//
// Created by Tomáš Petříček on 07.07.2021.
//

#ifndef MINIPROJECTS_KING_H
#define MINIPROJECTS_KING_H

#include "ChessPiece.h"

class King: public ChessPiece {
public:
    King(const Position &pos = {0, 0}, Player *owner = nullptr, Color color = Black);

    ~King() override = default;

    bool valid_move(const Position &pos) override;
};


#endif //MINIPROJECTS_KING_H

//
// Created by Tomáš Petříček on 17.07.2021.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include "ChessPiece.h"


class Queen: public ChessPiece {
private:
    static constexpr const int def_id = 4;
public:
    Queen(const Position &pos = {0, 0}, Player *owner = nullptr, Color color = Black);

    ~Queen() override = default;

    bool valid_move(const Position &pos) override;
};


#endif //CHESS_QUEEN_H

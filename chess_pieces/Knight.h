//
// Created by Tomáš Petříček on 17.07.2021.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H

#include "ChessPiece.h"


class Knight: public ChessPiece {
private:
    static constexpr const bool def_jumps_over = true;
    static constexpr const int def_id = 2;
public:
    explicit Knight(const Position &pos, Color color = Black);

    ~Knight() override = default;

    bool valid_move(const Position &pos) override;

    void print(std::ostream &os) const override;
};


#endif //CHESS_KNIGHT_H

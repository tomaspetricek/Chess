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
    Queen(const Position &pos, Color color = Black);

    ~Queen() override = default;

    bool valid_move(const Position &pos) override;

    void print(std::ostream &os) const override;
};


#endif //CHESS_QUEEN_H

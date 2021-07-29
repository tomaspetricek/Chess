//
// Created by Tomáš Petříček on 17.07.2021.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "ChessPiece.h"


class Rook: public ChessPiece {
private:
    static constexpr const int def_id = 1;
public:
    explicit Rook(const Position &pos, Color color = Black);

    ~Rook() override = default;

    bool valid_move(const Position &pos) override;

    void print(std::ostream &os) const override;
};


#endif //CHESS_ROOK_H

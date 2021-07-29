//
// Created by Tomáš Petříček on 17.07.2021.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "ChessPiece.h"


class Pawn : public ChessPiece {
private:
    static constexpr const int def_id = 6;
public:
    explicit Pawn(const Position &pos, Color color = Black);

    ~Pawn() override = default;

    bool valid_move(const Position &pos) override;

    void print(std::ostream &os) const override;
};


#endif //CHESS_PAWN_H

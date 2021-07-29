//
// Created by Tomáš Petříček on 17.07.2021.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include "ChessPiece.h"
#include "direction.h"


class Bishop : public ChessPiece {
private:
    static constexpr const int def_id = 3;
public:
    explicit Bishop(const Position &pos, Color color = Black);

    ~Bishop() override = default;

    bool valid_move(const Position &pos) override;

    void print(std::ostream &os) const override;
};


#endif //CHESS_BISHOP_H

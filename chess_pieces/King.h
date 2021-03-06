//
// Created by Tomáš Petříček on 17.07.2021.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "ChessPiece.h"

class King: public ChessPiece {
private:
    static constexpr const int def_id = 5;
public:
    explicit King(const Position &pos, Color color = Black);

    ~King() override = default;

    bool valid_move(const Position &pos) override;

    void print(std::ostream &os) const override;
};


#endif //CHESS_KING_H

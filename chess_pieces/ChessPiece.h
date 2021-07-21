//
// Created by Tomáš Petříček on 17.07.2021.
//

#ifndef CHESS_CHESSPIECE_H
#define CHESS_CHESSPIECE_H

#include "../Player.h"
#include "../Position.h"
#include <vector>
#include "../enums.h"
#include <cmath>
#include "direction.h"
// #include "../playground/Board.h"


class ChessPiece {
protected:
    Position pos;
    Color color;
    bool has_moved;
    int id;

public:
    const bool jumps_over;

    explicit ChessPiece(const Position &pos, Color color = Black,
                        bool jumps_over = false, int id = 0);

    virtual ~ChessPiece() = default;

    virtual bool valid_move(const Position &pos) = 0;
    // bool move(Position);
    // std::vector<Position> can_move_to(Board board);

    const Position &get_pos() const;

    void set_pos(const Position &pos);

    Color get_color() const;

    void set_color(Color color);

    bool get_has_moved() const;

    void set_has_moved(bool has_moved);

    int get_id() const;

    void set_id(int id);
};


#endif //CHESS_CHESSPIECE_H

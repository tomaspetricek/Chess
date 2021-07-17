//
// Created by Tomáš Petříček on 07.07.2021.
//

#ifndef MINIPROJECTS_CHESSPIECE_H
#define MINIPROJECTS_CHESSPIECE_H

#include "../Player.h"
#include "../Position.h"
#include <vector>
#include "../enums.h"
#include <cmath>
#include "direction.h"
// #include "../playground/Board.h"

class ChessPiece {
private:
protected:
    Position pos;
    Player *owner;
    Color color;
    bool has_moved;

public:
    static const bool jumps_over = false;

    explicit ChessPiece(const Position &pos = {0, 0}, Player *owner = nullptr, Color color = Black);

    virtual ~ChessPiece() = default;

    virtual bool valid_move(const Position &pos) = 0;
    // bool move(Position);
    // std::vector<Position> can_move_to(Board board);

    const Position &get_pos() const;

    void set_pos(const Position &pos);

    Player *get_owner() const;

    void set_owner(Player *owner);

    Color get_color() const;

    void set_color(Color color);

    bool is_has_moved() const;

    void set_has_moved(bool has_moved);
};

#endif //MINIPROJECTS_CHESSPIECE_H

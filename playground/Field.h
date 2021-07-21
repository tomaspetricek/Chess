//
// Created by Tomáš Petříček on 17.07.2021.
//

#ifndef CHESS_FIELD_H
#define CHESS_FIELD_H

#include "../chess_pieces/ChessPiece.h"
#include "../enums.h"
#include <memory>


class Field {
private:
    std::unique_ptr<ChessPiece> piece_ptr;
    Color color;
    const Position pos;
public:
    explicit Field(Position pos, Color color = Black);

    bool is_empty() const;

    Color get_color() const;

    void set_color(Color color);

    void remove_chess_piece();

    std::unique_ptr<ChessPiece> &get_piece_ptr();

    void set_piece_ptr(std::unique_ptr<ChessPiece> piece_ptr);

    const Position &get_pos() const;
};


#endif //CHESS_FIELD_H

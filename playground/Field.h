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
    std::shared_ptr<ChessPiece> chess_piece;
    Color color;
public:
    explicit Field(Color color = Black);

    bool is_empty() const;

    const std::shared_ptr<ChessPiece> & get_chess_piece() const;

    void set_chess_piece(const std::shared_ptr<ChessPiece> &chess_piece);

    Color get_color() const;

    void set_color(Color color);

    void add_chess_piece(const std::shared_ptr<ChessPiece>& chess_piece_ptr);

    void remove_chess_piece();
};


#endif //CHESS_FIELD_H

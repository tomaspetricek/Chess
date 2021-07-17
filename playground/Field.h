//
// Created by Tomáš Petříček on 17.07.2021.
//

#ifndef CHESS_FIELD_H
#define CHESS_FIELD_H

#include "../chess_pieces/ChessPiece.h"
#include "../enums.h"


class Field {
private:
    ChessPiece *chess_piece{nullptr};
    Color color;
public:
    Field(Color color);

    bool is_empty() const;

    ChessPiece *get_chess_piece() const;

    void set_chess_piece(ChessPiece *chess_piece);

    Color get_color() const;

    void set_color(Color color);

    void add_chess_piece(ChessPiece *chess_piece);

    void remove_chess_piece();
};


#endif //CHESS_FIELD_H

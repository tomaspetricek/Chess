//
// Created by Tomáš Petříček on 17.07.2021.
//

#ifndef CHESS_CHESS_H
#define CHESS_CHESS_H

#include "playground/Board.h"
#include "chess_pieces/ChessPiece.h"
#include "chess_pieces/King.h"
#include "chess_pieces/Rook.h"
#include "chess_pieces/Bishop.h"
#include "chess_pieces/Queen.h"
#include "chess_pieces/Pawn.h"
#include "chess_pieces/Knight.h"
#include "Position.h"
#include "enums.h"
#include <string>
#include <iostream>
#include "utils.h"
#include <typeinfo>
#include <memory>
#include "Printable.h"


class Chess : public Printable {
private:
    Board board;
    Color active_side;
    std::shared_ptr<Field> original_field_ptr;
    std::shared_ptr<Field> next_field_ptr;

    void place_pieces(Color color, int front_row, int back_row);

    static int get_actual_row(int row);

    static int get_actual_col(char col);

    std::shared_ptr<Field> &get_field(int row, char col);

    bool valid_movement();

public:
    Chess();

    ~Chess() override = default;

    void select_piece(int row, char col);

    void select_next_field(int row, char col);

    void make_move();

    void print(std::ostream &os) const override;

    bool piece_selected();

    bool next_field_selected();

    // bool perform_castling(King* king, Rook* rook);
};


#endif //CHESS_CHESS_H

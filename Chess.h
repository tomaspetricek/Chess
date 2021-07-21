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


class Chess {
private:
    Board board;
    Color active_side;
    std::shared_ptr<ChessPiece> selected_piece_ptr;
    std::shared_ptr<Field> selected_field_ptr;

    void place_pieces(Color color, int front_row, int back_row);

    void make_move();

    void choose_piece();

    void choose_next_position();

    static int choose_row();

    static int choose_col();

    bool valid_movement();

    static int ask_player(const std::string &question, const std::vector<std::string> &possible_answers);

    template<typename T>
    static T ask_player(const std::string &question, T min_answer, T max_answer);

public:
    Chess();

    ~Chess();

    void play();

    void pause();

    void resume();

    bool select_piece(int x, int y);

    bool move_selected_piece(int x, int y);

    // bool perform_castling(King* king, Rook* rook);
};


#endif //CHESS_CHESS_H

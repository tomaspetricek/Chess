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


class Chess {
private:
    Board board;
    Player *active_player{nullptr};
    ChessPiece *selected_piece{nullptr};

    void place_pieces();

    void choose_side();

    void valid_movement();

    static int ask_active_player(const std::string &question, const std::vector<std::string> &possible_answers);

public:
    Chess();

    ~Chess();

    void play();

    void pause();

    void resume();

    bool select_piece(int x, int y);

    bool move_selected_piece(int x, int y);

    bool perform_castling(King* king, Rook* rook);
};


#endif //CHESS_CHESS_H

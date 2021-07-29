//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "Chess.h"
#include <stdexcept>
#include <iostream>
#include "IllegalMove.h"

Chess::Chess() : board{}, active_side{White} {
    place_pieces(Black, 1, 0);
    place_pieces(White, Board::n_rows - 2, Board::n_rows - 1);
}

Chess::~Chess() = default;

void Chess::choose_piece(int row, int col) {
    std::shared_ptr<Field> field = board[row][col];

    if (field->is_empty())
        throw std::invalid_argument{"Field is empty."};

    if (field->get_piece_ptr()->get_color() != active_side)
        throw std::invalid_argument{"Chess piece doesn't belong to you."};

    selected_piece_ptr = field->get_piece_ptr();
}

void Chess::choose_next_field(int row, int col) {
    std::shared_ptr<Field> field = board[row][col];

    if (!field->is_empty())
        if (field->get_piece_ptr()->get_color() == active_side)
            throw std::invalid_argument{"Your chess piece already occupies that field."};

    selected_field_ptr = field;
}

int Chess::select_row(int row) {
    int actual_row = Board::n_rows - row;
    return actual_row;
}

int Chess::select_col(int col) {
    int actual_col = col - Board::min_col_label;
    return actual_col;
}

void Chess::place_pieces(Color color, int front_row, int back_row) {
    std::unique_ptr<ChessPiece> ptr;
    Position pos{0, 0};
    int piece;

    for (int c{0}; c < Board::n_cols; c++) {
        pos = Position{back_row, c};
        piece = (c <= Board::n_cols / 2) ? c : Board::n_cols - c - 1;

        switch (piece) {
            case 0:
                ptr = std::make_unique<Rook>(pos, color);
                break;
            case 1:
                ptr = std::make_unique<Knight>(pos, color);
                break;
            case 2:
                ptr = std::make_unique<Bishop>(pos, color);
                break;
            case 3:
                ptr = std::make_unique<Queen>(pos, color);
                break;
            case 4:
                ptr = std::make_unique<King>(pos, color);
                break;
            default:
                break;
        }

        // add piece to back row
        board[back_row][c]->set_piece_ptr(std::move(ptr));

        // add piece to front row
        board[front_row][c]->set_piece_ptr(std::make_unique<Pawn>(Position{front_row, c}, color));
    }
}

bool Chess::valid_movement() {
    return selected_piece_ptr->valid_move(selected_field_ptr->get_pos());
}

void Chess::print(std::ostream &os) const {
    os << board;
}

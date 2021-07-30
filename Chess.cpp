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

void Chess::select_piece(int row, char col) {
    std::shared_ptr<Field> field = get_field(row, col);

    if (field->is_empty())
        throw std::invalid_argument{"Field is empty."};

    if (field->get_piece_ptr()->get_color() != active_side)
        throw std::invalid_argument{"Chess piece doesn't belong to you."};

    original_field_ptr = field;
}

void Chess::select_next_field(int row, char col) {
    if (!original_field_ptr)
        throw std::logic_error{"Have to select chess piece first."};

    std::shared_ptr<Field> field = get_field(row, col);

    if (!field->is_empty())
        if (field->get_piece_ptr()->get_color() == active_side)
            throw std::invalid_argument{"Your chess piece already occupies that field."};

    next_field_ptr = field;
}

int Chess::get_actual_row(int row) {
    int actual_row = Board::n_rows - row;
    return actual_row;
}

int Chess::get_actual_col(char col) {
    int actual_col = col - Board::min_col_label;
    return actual_col;
}

std::shared_ptr<Field> &Chess::get_field(int row, char col) {
    int act_row = get_actual_row(row);
    int act_col = get_actual_col(col);

    return board[act_row][act_col];
}

void Chess::place_pieces(Color color, int front_row, int back_row) {
    std::unique_ptr<ChessPiece> ptr;
    Position pos;
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
    return original_field_ptr->get_piece_ptr()->valid_move(next_field_ptr->get_pos());
}

void Chess::print(std::ostream &os) const {
    os << board;
}

void Chess::make_move() {
    if (!original_field_ptr)
        throw std::logic_error{"Have to select chess piece first."};

    if (!next_field_ptr)
        throw std::logic_error{"Have to select next piece first."};

    std::shared_ptr<ChessPiece> piece = original_field_ptr->get_piece_ptr();

    if (!valid_movement())
        throw std::logic_error{"Making the move is against the rules."};

    next_field_ptr->set_piece_ptr(piece);
    original_field_ptr->reset_piece_ptr();

    original_field_ptr.reset();
    next_field_ptr.reset();
}

bool Chess::piece_selected() {
    return original_field_ptr != nullptr;
}

bool Chess::next_field_selected() {
    return next_field_ptr != nullptr;
}

//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "Board.h"
#include "iostream"
#include "../chess_pieces/ChessPiece.h"

Board::Board() {
    set_fields();
}

std::vector<Field>& Board::operator[](int index) {
    //int actual_index = n_rows - index;
    return fields[index];
}

std::vector<std::vector<Field>> Board::get_fields() const {
    return fields;
}

void Board::set_fields() {
    Color color;

    for (int r{0}; r < n_rows; r++) {
        std::vector<Field> row;
        for (int c{0}; c < n_cols; c++) {
            if (r % 2 == 0 && c % 2 == 0 || r % 2 != 0 && c % 2 != 0) {
                color = White;
            } else {
                color = Black;
            }
            row.emplace_back(color);
        }
        fields.push_back(row);
    }
}

std::ostream &operator<<(std::ostream &os, const Board &board) {
    int empty {0};
    ChessPiece *chess_piece {nullptr};
    int id;

    os << std::endl;
    for (const auto &row : board.fields) {
        for (const auto &field : row) {
            if (field.is_empty()){
                id = empty;
            } else {
                chess_piece = field.get_chess_piece();
                id = chess_piece->get_id();

                if (chess_piece->get_color() == Black) {
                    id *= -1;
                }
            }
            os << " " << id << " ";
        }
        os << std::endl;
    }

    return os;
}

bool Board::lies_on(const Position &pos) {
    return ((pos.get_x() >= 0 && pos.get_x() < n_cols) && (pos.get_y() >= 0 && pos.get_y() < n_rows));
}

std::ostream &operator<<(std::ostream &os, const RowIndex &row_idx) {
    std::string s;
    switch (row_idx) {
        case A:
            s = "A";
            break;
        case B:
            s = "B";
            break;
        case C:
            s = "C";
            break;
        case D:
            s = "D";
            break;
        case E:
            s = "E";
            break;
        case F:
            s = "F";
            break;
        case G:
            s = "G";
            break;
        case H:
            s = "H";
            break;
    };
    return os << s;
}

//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "Board.h"
#include <iostream>
#include <iomanip>
#include "../console_text.h"


Board::Board() {
    set_fields();
}

std::array<std::shared_ptr<Field>, Board::n_cols> &Board::operator[](int index) {
    return fields[index];
}

void Board::set_fields() {
    Color color;

    for (int r{0}; r < n_rows; r++) {
        std::vector<std::shared_ptr<Field>> row;
        for (int c{0}; c < n_cols; c++) {
            color = (r % 2 == 0 && c % 2 == 0 || r % 2 != 0 && c % 2 != 0) ? White : Black;
            fields[r][c] = std::make_shared<Field>(Position{r, c}, color);
        }
    }
}

bool Board::lies_on(const Position &pos) {
    return ((pos.get_x() >= 0 && pos.get_x() < n_cols) && (pos.get_y() >= 0 && pos.get_y() < n_rows));
}

std::vector<std::vector<std::shared_ptr<Field>>> Board::get_fields() const {
    return std::vector<std::vector<std::shared_ptr<Field>>>();
}

void Board::print(std::ostream &os) const {
    int empty{0};
    int id;
    const int width {4};
    int row_label = Board::max_row_label;
    char col_label = Board::min_col_label;

    for (const auto &row : fields) {
        os << std::setw(width) << ct::fg_blue << row_label-- << ct::fg_def;
        for (const auto &field : row) {
            if (field->is_empty()) {
                id = empty;
            } else {
                const auto &chess_piece = field->get_piece_ptr();
                id = chess_piece->get_id();

                if (chess_piece->get_color() == Black) {
                    id *= -1;
                }
            }
            os << std::setw(width) << id;
        }
        os << std::endl;
    }

    os << std::setw(width) << ' ' << ct::fg_blue;
    for (int c {0}; c < Board::n_cols; c++){
        os << std::setw(width) << col_label++;
    }

    os << ct::fg_def;
}

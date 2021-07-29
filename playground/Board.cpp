//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "Board.h"
#include "iostream"


Board::Board() {
    set_fields();
}

std::vector<std::shared_ptr<Field>> &Board::operator[](int index) {
    return fields[index];
}

void Board::set_fields() {
    Color color;
    Position pos{0, 0};

    for (int r{0}; r < n_rows; r++) {
        std::vector<std::shared_ptr<Field>> row;
        for (int c{0}; c < n_cols; c++) {
            if (r % 2 == 0 && c % 2 == 0 || r % 2 != 0 && c % 2 != 0) {
                color = White;
            } else {
                color = Black;
            }
            pos = Position{r, c};
            row.push_back(std::make_shared<Field>(pos, color));
        }
        fields.push_back(row);
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

    os << std::endl;
    for (const auto &row : fields) {
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
            os << " " << id << " ";
        }
        os << std::endl;
    }
}

//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "Board.h"


std::vector<Field>& Board::operator[](int index) {
    return fields[index];
}

Board::Board() {
    set_fields();
}

std::vector<std::vector<Field>> Board::get_fields() const {
    return fields;
}

void Board::set_fields() {
    Color color;

    for (int r{0}; r < height; r++) {
        std::vector<Field> row;
        for (int c{0}; c < width; c++) {
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

Board::~Board() = default;

std::ostream &operator<<(std::ostream &os, RowIndex row_idx) {
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

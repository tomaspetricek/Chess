//
// Created by Tomáš Petříček on 17.07.2021.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "Field.h"
#include <map>
#include <string>


enum RowIndex {
    A, B, C, D, E, F, G, H
};

std::ostream &operator<<(std::ostream &os, const RowIndex &row_idx);

class Board {
    friend std::ostream &operator<<(std::ostream &os, const Board &board);

public:
    static const int n_cols{8};
    static const int n_rows{n_cols};

    Board();

    ~Board() = default;

    std::vector<Field> &operator[](int index);

    static bool lies_on(const Position &pos);

private:
    std::vector<std::vector<Field>> fields;

    void set_fields();

public:
    std::vector<std::vector<Field>> get_fields() const;
};


#endif //CHESS_BOARD_H

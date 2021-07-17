//
// Created by Tomáš Petříček on 07.07.2021.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "Field.h"
#include <map>
#include <string>

enum RowIndex {
    A, B, C, D, E, F, G, H
};

std::ostream &operator<<(std::ostream &os, RowIndex row_idx);

class Board {
public:
    static const int width{8};
    static const int height{width};


    Board();

    ~Board();

    std::vector<Field> &operator[](int index);

private:
    std::vector<std::vector<Field>> fields;

    void set_fields();

public:
    std::vector<std::vector<Field>> get_fields() const;
};

#endif //CHESS_BOARD_H

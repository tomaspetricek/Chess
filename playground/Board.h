//
// Created by Tomáš Petříček on 17.07.2021.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "Field.h"
#include <map>
#include <string>
#include <memory>


class Board {
    friend std::ostream &operator<<(std::ostream &os, const Board &board);

private:
    std::vector<std::vector<std::shared_ptr<Field>>> fields;

    void set_fields();

public:
    static const int n_cols{8};
    static const int n_rows{n_cols};

    Board();

    ~Board() = default;

    std::vector<std::shared_ptr<Field>>& operator[](int index);

    static bool lies_on(const Position &pos);

    std::vector<std::vector<std::shared_ptr<Field>>> get_fields() const;
};


#endif //CHESS_BOARD_H

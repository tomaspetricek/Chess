//
// Created by Tomáš Petříček on 17.07.2021.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "Field.h"
#include <map>
#include <string>
#include <memory>
#include "../Printable.h"
#include <array>

class Field;

class Board : public Printable {
public:
    static constexpr const int n_cols{8};
    static constexpr const int n_rows{n_cols};
    static constexpr const int min_row_label{1};
    static constexpr const int max_row_label{n_cols};
    static constexpr const char min_col_label{'A'};
    static constexpr const char max_col_label{'H'};

    Board();

    ~Board() override = default;

    std::array<std::shared_ptr<Field>, Board::n_cols> &operator[](int index);

    static bool lies_on(const Position &pos);

    std::vector<std::vector<std::shared_ptr<Field>>> get_fields() const;

    void print(std::ostream &os) const override;

private:
    std::array<std::array<std::shared_ptr<Field>, Board::n_cols>, Board::n_rows> fields;

    void set_fields();
};


#endif //CHESS_BOARD_H

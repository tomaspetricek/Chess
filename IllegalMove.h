//
// Created by Tomáš Petříček on 27.07.2021.
//

#ifndef CHESS_ILLEGALMOVE_H
#define CHESS_ILLEGALMOVE_H

#include <exception>

class IllegalMove : public std::exception {
public:
    ~IllegalMove() noexcept override = default;

    const char *what() const noexcept override {
        return "Trying to make an illegal move".
    }
};

#endif //CHESS_ILLEGALMOVE_H

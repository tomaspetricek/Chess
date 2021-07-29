//
// Created by Tomáš Petříček on 29.07.2021.
//

#ifndef CHESS_COLOR_H
#define CHESS_COLOR_H

#include <ostream>
namespace cc{
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };

    static std::ostream& operator<<(std::ostream& os, Code code) {
        return os << "\033[" << int(code) << "m";
    }
}

#endif //CHESS_COLOR_H

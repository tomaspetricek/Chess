//
// Created by Tomáš Petříček on 29.07.2021.
//

#ifndef CHESS_CONSOLE_TEXT_H
#define CHESS_CONSOLE_TEXT_H

#include <ostream>
namespace ct{
    enum Code {
        reset            =  0,
        bold             =  1,
        underline        =  4,
        inverse          =  7,
        bold_off         = 21,
        underline_off    = 24,
        inverse_off      = 27,

        fg_black         = 30,
        fg_red           = 31,
        fg_green         = 32,
        fg_yellow        = 33,
        fg_blue          = 34,
        fg_magenta       = 35,
        fg_cyan          = 36,
        fg_white         = 37,
        fg_def           = 39,

        bg_black         = 10 + fg_black,
        bg_red           = 10 + fg_red,
        bg_green         = 10 + fg_green,
        bg_yellow        = 10 + fg_yellow,
        bg_blue          = 10 + fg_blue,
        bg_magenta       = 10 + fg_magenta,
        bg_cyan          = 10 + fg_cyan,
        bg_white         = 10 + fg_white,
        bg_def           = 10 + fg_def,
    };

    static std::ostream& operator<<(std::ostream& os, Code code) {
        return os << "\033[" << int(code) << "m";
    }
}

#endif //CHESS_CONSOLE_TEXT_H

//
// Created by Tomáš Petříček on 08.07.2021.
//

#ifndef CHESS_UTILS_H
#define CHESS_UTILS_H

#include <sstream>

template <typename T>
std::string to_string(const T& value) {
    std::ostringstream os;
    os << value;
    return os.str();
}

#endif //CHESS_UTILS_H


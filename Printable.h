//
// Created by Tomáš Petříček on 29.07.2021.
//

#ifndef CHESS_PRINTABLE_H
#define CHESS_PRINTABLE_H

#include <iostream>

class Printable {
    friend std::ostream &operator<<(std::ostream& os, const Printable &obj);
public:
    virtual void print(std::ostream &os) const = 0;

    virtual ~Printable() = default;
};


#endif //CHESS_PRINTABLE_H

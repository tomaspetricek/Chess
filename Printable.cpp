//
// Created by Tomáš Petříček on 29.07.2021.
//

#include "Printable.h"

std::ostream &operator<<(std::ostream &os, const Printable &obj) {
    obj.print(os);
    return os;
}

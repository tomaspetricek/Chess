#include <iostream>
#include "Position.h"
#include "chess_pieces/Queen.h"
#include "chess_pieces/Knight.h"

int main() {
    Position p {0, 0};
    Queen queen {{0, 0}};
    //Knight knight {};

    std::cout << Queen::jumps_over << std::endl;
    std::cout << Knight::jumps_over << std::endl;
    return 0;
}

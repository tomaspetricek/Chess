#include <iostream>
#include "Position.h"
#include "chess_pieces/Queen.h"
#include "chess_pieces/Knight.h"

int main() {
    // Knight knight {};
    ChessPiece* knight = new Knight {};
    std::cout << knight->jumps_over << std::endl;
    delete knight;
    return 0;
}

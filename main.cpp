#include <iostream>
#include "Position.h"
#include "chess_pieces/Queen.h"
#include "chess_pieces/Knight.h"
#include "playground/Board.h"
#include "Chess.h"

int main() {
    // Knight knight {};
    /*
    ChessPiece* knight = new Knight {};
    std::cout << knight->jumps_over << std::endl;
    delete knight;
    */

    Chess c {};
    c.play();

    return 0;
}

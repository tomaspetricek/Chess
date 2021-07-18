//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "ChessSet.h"

ChessSet::ChessSet(Color color, Player *owner) : color{color}, owner{nullptr} {
    set_pieces();
}

void ChessSet::set_pieces() {
    std::vector<int> lines = (color == Black) ? std::vector<int>{0, 1} : std::vector<int>{7, 6};
    ChessPiece *piece {nullptr};

    for (int y {0}; y < pieces.size(); y++) {
        for (int x {0}; x < pieces[y].size(); x++){
            piece = pieces[y][x];
            piece->set_color(color);
            piece->set_pos({x, lines[y]});
        }
    }
}

ChessSet::~ChessSet() {
    for (auto& row: pieces)
        for (auto& piece : row)
            delete piece;

    pieces.clear();
}

const std::vector<std::vector<ChessPiece *>> &ChessSet::get_pieces() const {
    return pieces;
}

//
// Created by Tomáš Petříček on 17.07.2021.
//

#ifndef CHESS_CHESSSET_H
#define CHESS_CHESSSET_H

#include "Player.h"
#include <vector>
#include "chess_pieces/ChessPiece.h"
#include "enums.h"
#include <map>
#include "chess_pieces/ChessPiece.h"
#include "chess_pieces/Knight.h"
#include "chess_pieces/King.h"
#include "chess_pieces/Rook.h"
#include "chess_pieces/Bishop.h"
#include "chess_pieces/Pawn.h"
#include "chess_pieces/Queen.h"
#include "chess_pieces/Pawn.h"
#include "Position.h"


class ChessSet {
private:
    std::vector<std::vector<ChessPiece*>> pieces {
            {new Rook, new Knight, new Bishop, new Queen,
                    new King, new Bishop, new Knight, new Rook},
            {new Pawn, new Pawn, new Pawn, new Pawn,
                    new Pawn, new Pawn, new Pawn, new Pawn}
    };

    Color color;

    Player *owner;

    void set_pieces();

public:
    static int n_remaining_pieces;

    explicit ChessSet(Color color = Black, Player *owner = nullptr);

    const std::vector<std::vector<ChessPiece *>> &get_pieces() const;

    ~ChessSet();
};


#endif //CHESS_CHESSSET_H

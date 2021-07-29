cmake_minimum_required(VERSION 3.17)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chess main.cpp Position.cpp Position.h Player.cpp Player.h Chess.cpp Chess.h chess_pieces/Bishop.cpp chess_pieces/Bishop.h chess_pieces/ChessPiece.cpp chess_pieces/ChessPiece.h chess_pieces/direction.cpp chess_pieces/direction.h chess_pieces/King.cpp chess_pieces/King.h chess_pieces/Knight.cpp chess_pieces/Knight.h chess_pieces/Pawn.cpp chess_pieces/Pawn.h chess_pieces/Queen.cpp chess_pieces/Queen.h chess_pieces/Rook.cpp chess_pieces/Rook.h enums.h playground/Board.cpp playground/Board.h playground/Field.cpp playground/Field.h IllegalMove.h Gui.cpp Gui.h Printable.cpp Printable.h color.h)
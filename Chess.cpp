//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "Chess.h"

Chess::Chess() : board{}, active_side{White} {}

Chess::~Chess() = default;

void Chess::play() {
    place_pieces(black_chess_set);
    place_pieces(white_chess_set);
    std::cout << board << std::endl;

    make_move();
}

void Chess::make_move() {
    choose_piece();
    choose_next_position();
    //valid_movement();
}

void Chess::choose_piece() {
    int row{0}, col{0};
    bool piece_picked{false};
    Field field {};

    do {
        row = choose_row();
        col = choose_col();
        field = board[row][col];

        if (field.is_empty()) {
            std::cout << "Field is empty." << std::endl;
            continue;
        }

        if (field.get_chess_piece()->get_color() != active_side) {
            std::cout << "Chess piece doesn't belong to you." << std::endl;
            continue;
        }

        piece_picked = true;
        selected_piece = field.get_chess_piece();
    } while (!piece_picked);
}

void Chess::choose_next_position() {
    int row = choose_row();
    int col = choose_col();
}

int Chess::choose_row() {
    std::string question = "Choose row.";
    int min_row = 1;
    int max_row = 8;
    int row = ask_player(question, min_row, max_row);
    int actual_row = Board::n_rows - row;
    return actual_row;
}

int Chess::choose_col() {
    std::string question = "Choose col.";
    char min_col = 'A';
    char max_col = 'H';
    char col = ask_player(question, min_col, max_col);
    int actual_col = col - 'A';
    return actual_col;
}

void Chess::place_pieces(const ChessSet &chess_set) {
    Position pos{0, 0};
    int x = 0, y = 0;

    for (const auto &row : chess_set.get_pieces()) {
        for (const auto &piece : row) {
            pos = piece->get_pos();
            x = pos.get_x();
            y = pos.get_y();
            board[y][x].add_chess_piece(piece);
        }
    }
}

int Chess::ask_player(const std::string &question, const std::vector<std::string> &possible_answers) {
    int answer{0};
    bool valid_answer{false};

    std::cout << question << std::endl;

    do {
        for (int i{0}; i < possible_answers.size(); i++)
            std::cout << i + 1 << ": " << possible_answers[i] << std::endl;

        std::cin >> answer;

        if (answer > 0 && answer <= possible_answers.size()) {
            valid_answer = true;
        } else {
            std::cout << "Entered invalid answer. Try again." << std::endl;
        }

    } while (!valid_answer);

    return answer;
}

bool Chess::select_piece(int x, int y) {
    /* auto it = board.row_indices.find('A');
    Field f = board[0][it->second];
    std::cout << f.get_color() << std::endl;*/
    return true;
}

template<typename T>
T Chess::ask_player(const std::string &question, T min_answer, T max_answer) {
    T answer{};
    bool valid_answer{false};

    std::cout << question << "<" << min_answer << "," << max_answer << ">" << std::endl;

    do {
        std::cin >> answer;

        if (answer >= min_answer && answer <= max_answer) {
            valid_answer = true;
        } else {
            std::cout << "Entered invalid answer. Try again." << std::endl;
        }

    } while (!valid_answer);

    return answer;
}

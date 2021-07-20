//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "Chess.h"

Chess::Chess() : board{}, active_side{White} {}

Chess::~Chess() = default;

void Chess::play() {
    place_pieces(Black, 1, 0);
    place_pieces(White, Board::n_rows - 2, Board::n_rows - 1);
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
    std::shared_ptr<Field> field;

    do {
        row = choose_row();
        col = choose_col();
        field = board[row][col];

        if (field->is_empty()) {
            std::cout << "Field is empty." << std::endl;
            continue;
        }

        if (field->get_chess_piece()->get_color() != active_side) {
            std::cout << "Chess piece doesn't belong to you." << std::endl;
            continue;
        }

        piece_picked = true;
        selected_piece = field->get_chess_piece();
    } while (!piece_picked);
}

void Chess::choose_next_position() {
    int row{0}, col{0};
    bool position_picked{false};
    std::shared_ptr<Field> field;

    do {
        row = choose_row();
        col = choose_col();
        field = board[row][col];

        if (!field->is_empty()) {
            if (field->get_chess_piece()->get_color() == active_side) {
                std::cout << "Your chess piece already occupies that field." << std::endl;
                continue;
            }
        }

        selected_field = field;
        position_picked = true;
    } while (!position_picked);
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

void Chess::place_pieces(Color color, int front_row, int back_row) {
    board[back_row][0]->add_chess_piece(std::make_shared<Rook>(Position{back_row, 0}, color));
    board[back_row][1]->add_chess_piece(std::make_shared<Knight>(Position{back_row, 1}, color));
    board[back_row][2]->add_chess_piece(std::make_shared<Bishop>(Position{back_row, 2}, color));
    board[back_row][3]->add_chess_piece(std::make_shared<Queen>(Position{back_row, 3}, color));
    board[back_row][4]->add_chess_piece(std::make_shared<King>(Position{back_row, 4}, color));
    board[back_row][5]->add_chess_piece(std::make_shared<Bishop>(Position{back_row, 5}, color));
    board[back_row][6]->add_chess_piece(std::make_shared<Knight>(Position{back_row, 6}, color));
    board[back_row][7]->add_chess_piece(std::make_shared<Rook>(Position{back_row, 7}, color));

    for (int c{0}; c < Board::n_cols; c++) {
        board[front_row][c]->add_chess_piece(std::make_shared<Pawn>(Position{front_row, c}, color));
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

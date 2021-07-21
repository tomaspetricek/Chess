//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "Chess.h"

Chess::Chess() : board{}, active_side{White} {}

Chess::~Chess() = default;

void Chess::play() {
    place_pieces(Black, 1, 0);
    place_pieces(White, Board::n_rows - 2, Board::n_rows - 1);

    do {
        std::cout << board << std::endl;

        make_move();

        active_side = (active_side == Black) ? White : Black;
    } while (true);
}

void Chess::make_move() {
    bool valid_move{false};

    do {
        choose_piece();
        choose_next_field();
        valid_move = valid_movement();
    } while (!valid_move);

    selected_field_ptr->set_piece_ptr(std::move(selected_piece_ptr));
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

        if (field->get_piece_ptr()->get_color() != active_side) {
            std::cout << "Chess piece doesn't belong to you." << std::endl;
            continue;
        }

        piece_picked = true;
        selected_piece_ptr = std::move(field->get_piece_ptr());
    } while (!piece_picked);
}

void Chess::choose_next_field() {
    int row{0}, col{0};
    bool position_picked{false};
    std::shared_ptr<Field> field;

    do {
        row = choose_row();
        col = choose_col();
        field = board[row][col];

        if (!field->is_empty()) {
            if (field->get_piece_ptr()->get_color() == active_side) {
                std::cout << "Your chess piece already occupies that field." << std::endl;
                continue;
            }
        }

        selected_field_ptr = field;
        position_picked = true;
    } while (!position_picked);
}

int Chess::choose_row() {
    std::string question = "Choose row.";
    int min_row = Board::min_row_label;
    int max_row = Board::max_row_label;
    int row = ask_player(question, min_row, max_row);
    int actual_row = Board::n_rows - row;
    return actual_row;
}

int Chess::choose_col() {
    std::string question = "Choose col.";
    char min_col = Board::min_col_label;
    char max_col = Board::max_col_label;
    char col = ask_player(question, min_col, max_col);
    int actual_col = col - Board::min_col_label;
    return actual_col;
}

void Chess::place_pieces(Color color, int front_row, int back_row) {
    std::unique_ptr<ChessPiece> ptr;
    Position pos{0, 0};
    int piece;

    for (int c{0}; c < Board::n_cols; c++) {
        pos = Position{back_row, c};
        piece = (c <= Board::n_cols / 2) ? c : Board::n_cols - c - 1;

        switch (piece) {
            case 0:
                ptr = std::make_unique<Rook>(pos, color);
                break;
            case 1:
                ptr = std::make_unique<Knight>(pos, color);
                break;
            case 2:
                ptr = std::make_unique<Bishop>(pos, color);
                break;
            case 3:
                ptr = std::make_unique<Queen>(pos, color);
                break;
            case 4:
                ptr = std::make_unique<King>(pos, color);
                break;
            default:
                break;
        }

        // add piece to back row
        board[back_row][c]->set_piece_ptr(std::move(ptr));

        // add piece to front row
        board[front_row][c]->set_piece_ptr(std::make_unique<Pawn>(Position{front_row, c}, color));
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

bool Chess::valid_movement() {
    return selected_piece_ptr->valid_move(selected_field_ptr->get_pos());
}

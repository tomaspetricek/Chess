//
// Created by Tomáš Petříček on 17.07.2021.
//

#include "Chess.h"

Chess::Chess() : board(Board()), active_player(new Player()) {}

Chess::~Chess() {
    delete active_player;
}

void Chess::play() {
    place_pieces();

    // choose_side();
}

void Chess::place_pieces() {
    std::cout << A << std::endl;
    /*
    board[0][0].add_chess_piece(new Knight{Black});
    board[0][1].add_chess_piece(new Knight{Black});
    board[0][2].add_chess_piece(new Bishop{Black});
    board[0][3].add_chess_piece(new Queen{Black});
    board[0][4].add_chess_piece(new King{Black});
    board[0][2].add_chess_piece(new Bishop{Black});
    board[0][1].add_chess_piece(new Knight{Black});
    board[0][0].add_chess_piece(new Rook{Black});

    // board[1][0].add_chess_piece(new Pawn{Black});

    board[7][0].add_chess_piece(new Rook{White});
    board[7][1].add_chess_piece(new Knight{White});
    board[7][2].add_chess_piece(new Bishop{White});
    board[7][3].add_chess_piece(new Queen{White});
    board[7][4].add_chess_piece(new King{White});
    board[7][2].add_chess_piece(new Bishop{White});
    board[7][1].add_chess_piece(new Knight{White});
    board[7][0].add_chess_piece(new Rook{White});
    */
}

void Chess::choose_side() {
    std::string message{"Which side would you like to join?"};
    std::vector<std::string> possible_answers{"Black", "White"};
    int idx = ask_active_player(message, possible_answers);

    Color answers[]{Black, White};
    Color color = answers[idx];

    active_player->set_side(color);

    select_piece(0, 0);
}

int Chess::ask_active_player(const std::string &question, const std::vector<std::string> &possible_answers) {
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

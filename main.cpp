#include <iostream>
#include "Position.h"
#include "chess_pieces/Queen.h"
#include "chess_pieces/Knight.h"
#include "playground/Board.h"
#include "Chess.h"
#include "color.h"


template<typename T>
T ask(const std::string &question, T min_answer, T max_answer) {
    T answer{};

    std::cout << question << "<" << min_answer << "," << max_answer << ">" << std::endl;

    std::cin >> answer;

    // check if user entered valid input type
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument{"Invalid input type."};
    }

    if (answer < min_answer || answer > max_answer) {
        std::stringstream ss {};
        ss << "Input " << answer << " is out of range.";
        ss << "Expected input within range <" << min_answer << ";" << max_answer << ">.";
        throw std::out_of_range{ss.str()};
    }

    return answer;
}

int ask(const std::string &question, const std::vector<std::string> &possible_answers) {
    std::stringstream ss;

    ss << question << std::endl;

    for (int i{0}; i < possible_answers.size(); i++)
        ss << i + 1 << ": " << possible_answers[i] << std::endl;

    return ask(ss.str(), 0, (int) possible_answers.size());
}

int main() {
    Chess chess;

    std::cout << chess << std::endl;

    return 0;
}

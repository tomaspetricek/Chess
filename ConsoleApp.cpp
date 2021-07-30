//
// Created by Tomáš Petříček on 30.07.2021.
//

#include "ConsoleApp.h"
#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include "Callback.h"
#include "console_text.h"


template<typename T>
T ask(const std::string &question, T min_answer, T max_answer) {
    T answer{};

    std::cout << ct::inverse;
    std::cout << question << "<" << min_answer << "," << max_answer << ">" << std::endl;
    std::cout << ct::inverse_off;

    std::cin >> answer;

    // check if user entered valid input type
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument{"Invalid input type."};
    }

    if (answer < min_answer || answer > max_answer) {
        std::stringstream ss{};
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

    return ask(ss.str(), 1, (int) possible_answers.size());
}

ConsoleApp::ConsoleApp() : chess{} {}

void ConsoleApp::run() {
    bool playing{true};
    std::pair<std::vector<std::string>, std::vector<Callback<ConsoleApp, void>>> menu_opts;

    do {
        std::cout << chess << std::endl;

        menu_opts = std::move(get_menu_opts());
        int idx = ask("Choose one of the options bellow.", menu_opts.first);
        menu_opts.second[idx - 1]();

    } while (playing);
}

void ConsoleApp::select_piece() {
    chess.select_piece(2, 'A');
}

void ConsoleApp::select_next_field() {
    chess.select_next_field(3, 'A');
}

void ConsoleApp::make_move() {
    chess.make_move();
}

std::pair<std::vector<std::string>, std::vector<Callback<ConsoleApp, void>>> ConsoleApp::get_menu_opts() {
    std::pair<std::vector<std::string>, std::vector<Callback<ConsoleApp, void>>> menu_opts;

    menu_opts.first.emplace_back("Select chess piece.");
    menu_opts.second.emplace_back(this, &ConsoleApp::select_piece);

    if (chess.piece_selected()) {
        menu_opts.first.emplace_back("Select next field.");
        menu_opts.second.emplace_back(this, &ConsoleApp::select_next_field);

        if (chess.next_field_selected()) {
            menu_opts.first.emplace_back("Make move.");
            menu_opts.second.emplace_back(this, &ConsoleApp::make_move);
        }
    }
    return menu_opts;
}

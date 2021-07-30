//
// Created by Tomáš Petříček on 30.07.2021.
//

#include "ConsoleApp.h"
#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include "Callback.h"


ConsoleApp::ConsoleApp() : chess{} {}

void ConsoleApp::run() {
    bool playing{true};

    std::vector<std::pair<std::string, Callback<ConsoleApp, void>>> menu_opts;

    do {
        std::cout << chess << std::endl;

        menu_opts.push_back({{"Select chess piece"}, {this, &ConsoleApp::select_piece}});
        menu_opts[0].second();

        chess.select_piece(2, 'A');
        chess.select_next_field(3, 'A');
        chess.make_move();
        break;
    } while (playing);
}

void ConsoleApp::select_piece() {
    std::cout << "Hello" << std::endl;
    //chess.select_piece();
}
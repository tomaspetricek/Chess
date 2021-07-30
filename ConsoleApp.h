//
// Created by Tomáš Petříček on 30.07.2021.
//

#ifndef CHESS_CONSOLEAPP_H
#define CHESS_CONSOLEAPP_H
#include "Chess.h"
#include "Callback.h"
#include <string>
#include <vector>

class ConsoleApp {
private:
    Chess chess;

    std::pair<std::vector<std::string>, std::vector<Callback<ConsoleApp, void>>> get_menu_opts();

public:
    ConsoleApp();

    void run();

    void select_piece();

    void make_move();

    void select_next_field();
};


#endif //CHESS_CONSOLEAPP_H

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

    void select_piece();

    void make_move();

    void select_next_field();

    static int select_row();

    static char select_col();
public:
    ConsoleApp();

    void run();
};


#endif //CHESS_CONSOLEAPP_H

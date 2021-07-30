//
// Created by Tomáš Petříček on 30.07.2021.
//

#ifndef CHESS_CONSOLEAPP_H
#define CHESS_CONSOLEAPP_H
#include "Chess.h"

class ConsoleApp {
private:
    Chess chess;

public:
    ConsoleApp();

    void run();

    void select_piece();
};


#endif //CHESS_CONSOLEAPP_H

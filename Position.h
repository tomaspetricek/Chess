//
// Created by Tomáš Petříček on 07.07.2021.
//

#ifndef CHESS_POSITION_H
#define CHESS_POSITION_H


class Position {
private:
    int x;
    int y;
public:
    Position(int x, int y);

    int get_x() const;

    void set_x(int x);

    int get_y() const;

    void set_y(int y);
};


#endif //CHESS_POSITION_H

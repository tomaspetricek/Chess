//
// Created by Tomáš Petříček on 17.07.2021.
//

#ifndef CHESS_POSITION_H
#define CHESS_POSITION_H


class Position {
private:
    int x;
    int y;
public:
    explicit Position(int x = 0, int y = 0);

    int get_x() const;

    void set_x(int x);

    int get_y() const;

    void set_y(int y);
};



#endif //CHESS_POSITION_H

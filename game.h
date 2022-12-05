#ifndef GAME_H
#define GAME_H
#include "board.h"
#include <iostream>

using Graph_lib::Point;
using Graph_lib::Address;

struct Game: Graph_lib::Window
{
    Game (Point xy);
    
private:
    Gameboard board;

    static void cb_clicked(Address, Address widget) {
        auto &btn = Graph_lib::reference_to<Cell>(widget);
        dynamic_cast<Game &>(btn.window()).clicked(btn);
    }

    void clicked(Cell &c);
};


#endif // GAME_H

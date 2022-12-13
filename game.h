#ifndef GAME_H
#define GAME_H

#include <algorithm>
#include <iostream>
#include "game.h"
#include "board.h"
#include "Graph_lib/Regular_hexagon.h"

using Graph_lib::Address;


struct Game: Graph_lib::Window
{
    Game (Graph_lib::Point xy);
    ~Game(){};
private:
    Gameboard board;

    static void cb_clicked(Address, Address widget) 
    {
        auto &btn = Graph_lib::reference_to<Cell>(widget);
        dynamic_cast<Game &>(btn.window()).clicked(btn);
    }

    void clicked(Cell &c);
    Cell* active_cell = nullptr;
    std::vector<bool> dell_cell = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
};

#endif // GAME_H

#ifndef GAME_H
#define GAME_H
#include "board.h"

struct Game
{
    Gameboard board;

    static void cb_clicked();

    void clicked(Cell& c);
};


#endif // GAME_H

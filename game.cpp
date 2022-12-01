#include "game.h"
#include "board.h"
using namespace Graph_lib;

Game::Game(Point xy)
        : Window{xy, Gameboard::size, Gameboard::size, "Checkers"}, board{Point{0, 0}, cb_clicked} {
    size_range(Gameboard::size, Gameboard::size,
               Gameboard::size, Gameboard::size);  // fixed window size

}
void Game::clicked(Cell& c)
{
    
}

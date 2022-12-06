#include "game.h"
#include "board.h"
#include "Graph_lib/Regular_hexagon.h"
#include "cell.h"
#include <iostream>
using namespace Graph_lib;

Game::Game(Point xy)
        : Window{Point(0, 0), 840, 639, "Find a pair cyberpunk"}, board{Point{0, 0}, cb_clicked} {
    size_range(Gameboard::lenghth, Gameboard::width, Gameboard::lenghth, Gameboard::width);
    board.attach(*this);
}
void Game::clicked(Cell& c)
{   /*
    std::cerr<<"ccc";
    if (board.has_selected()) {
        Cell &selected_cell = board.get_selected();
        if (board.get_selected().type != c.type) {
            selected_cell.deactivate(*this, selected_cell.center());
            c.deactivate(*this, c.center());
        }
        if (board.get_selected().type == c.type) {
            c.is_deleted = false;
            selected_cell.is_deleted = false;
        // something
        }
    }
    Fl::redraw();
    */
   Fl::redraw();
}
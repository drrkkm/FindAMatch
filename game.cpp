#include "game.h"

using namespace Graph_lib;

Game::Game(Point xy)
        : Window{Point(0, 0), 840, 639, "Find a pair cyberpunk"}, board{Point{0, 0}, cb_clicked} {
    size_range(Gameboard::lenghth, Gameboard::width, Gameboard::lenghth, Gameboard::width);
    board.attach(*this);
}
//void Game::clicked(Cell& c)
//{
//    std::cerr<<"ccc";
//    if (board.has_selected()) {
//        Cell &selected_cell = board.get_selected();
//        if (board.get_selected().type != c.type) {
//            std::cerr<<"ccc1";
//            selected_cell.deactivate(*this, selected_cell.center());
//            c.deactivate(*this, c.center());
//        }
//        if (board.get_selected().type == c.type) {
//            c.is_deleted = false;
//            selected_cell.is_deleted = false;
//        // something
//        }
//    }
//    Fl::redraw();

//}


void Game::clicked(Cell& c)
{
    std::cerr<<"ccc ";
    c.activate(*this);
    Fl::redraw();
}

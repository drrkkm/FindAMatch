#include "game.h"

using namespace Graph_lib;

Game::Game(Point xy)
        : Window{Point(0, 0), 840, 639, "Find a pair cyberpunk"}, board{Point{0, 0}, cb_clicked} {
    size_range(Gameboard::lenghth, Gameboard::width, Gameboard::lenghth, Gameboard::width);

    board.attach_game(*this, true);
    board.attach(*this);
    if (std::all_of(dell_cell.begin(), dell_cell.end(), [](bool v) { return v; })){
        board.attach_game(*this, false);
    }
}


void Game::clicked(Cell& c)
try{
    if (active_cell != &c)
    {
        (active_cell != nullptr)? c.activate(*this): c.activate(*this) ;
    }
    cerr << c.type << " ";
    if (active_cell != nullptr && active_cell != &c) {
        cerr << active_cell->type << " ";
        if (active_cell->type != c.type) {
            if (dell_cell[c.type] != true){c.deactivate(*this, c.center());}
            if (dell_cell[active_cell->type] != true){active_cell->deactivate(*this, active_cell->center());}
            active_cell = nullptr;
        }
        else if ((active_cell->type == c.type && active_cell != &c) && !(active_cell->is_deleted && c.is_deleted)) {
            active_cell->is_deleted = false;
            c.is_deleted = false;
            dell_cell[c.type] = true;
            active_cell = nullptr;
        }
    }
    else
        active_cell = &c;
    Fl::redraw();

}
catch (std::exception& e){
    cerr<< e.what();
}


#include "game.h"

using namespace Graph_lib;

Game::Game(Point xy)
        : Window{Point(0, 0), 840, 639, "Find a pair cyberpunk"}, board{Point{0, 0}, cb_clicked} {
    size_range(Gameboard::lenghth, Gameboard::width, Gameboard::lenghth, Gameboard::width);
    board.attach(*this);
}


ostream& operator << (ostream& os, vector<bool> vec){
    for (bool i : vec){
        os << i << " ";
    }
    return os;
}


void Game::clicked(Cell& c)
try{

    std::cerr<<"ccc ";
    c.activate(*this);
    cerr << c.type << " ";
    if (active_cell != nullptr) {
        cerr << active_cell->type << " ";
        if (active_cell->type != c.type) {
            std::cerr<<dell_cell << endl;
            if (dell_cell[c.type] != true){c.deactivate(*this, c.center());}
            if (dell_cell[active_cell->type] != true){active_cell->deactivate(*this, active_cell->center());}
            active_cell = nullptr;
        }
        else if ((active_cell->type == c.type && active_cell != &c) && !(active_cell->is_deleted && c.is_deleted)) {
            std::cerr<<"ccc3" << endl;
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


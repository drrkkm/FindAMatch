
#include "Graph_lib/Regular_hexagon.h"
#include "cell.h"
#include <iostream>
#include "board.h"
#include "pictures.h"
using namespace Graph_lib;


Gameboard::Gameboard(Point xy, Graph_lib::Callback cb_clicked) : Widget{xy, size, size, "Gameboard", nullptr} {
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            cells.push_back(new Cell{ Point{i * Cell::size, j * Cell::size}, cb_clicked});
        }
    }
    
}

void Gameboard::attach (Graph_lib::Window& win)
{
    for (int i = 0; i < cells.size(); ++i)
        win.attach(cells[i]);

    own = &win;
}


void Gameboard::select (Graph_lib::Window &win, Cell& c)
{
    std::cerr<<"bbb";
    if (selected)
        selected->deactivate(win, c.center());

    if (selected != &c)
    {
        selected = &c;
        selected->activate(win, c.center(), pictures[c.type]);
    }
    else
        selected = nullptr;
}


Cell& Gameboard::get_selected()
{   
    std::cerr<<"aaa";
    if (!selected)
        error ("Gameboard::get_selected(): none of cells is selected");

    return *selected;
}

#include "Regular_hexagon.h"
#include "cell.h"
#include <iostream>
#include "board.h"
#include "pictures.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"


Gameboard::Gameboard (Point xy, Graph_lib::Callback cb_clicked)
        : Widget{ xy, size, size, "Gameboard", nullptr }
{

}
Graph_lib::Vector_ref<Cell> Gameboard::give_cells() {
    return cells;
}

void Gameboard::show (Graph_lib::Window& win)
{
    for (int i = 0; i < cells.size(); i++)
    {
        win.attach(cells[i]);
    }
}


void Gameboard::attach (Graph_lib::Window& win)
{
    for (int i = 0; i < cells.size(); ++i)
        win.attach (cells[i]);
    own = &win;
}


void Gameboard::select (Graph_lib::Window &win, Cell& c)
{
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


Cell& Gameboard::get_selected ()
{
    if (!selected)
        error ("Gameboard::get_selected(): none of cells is selected");

    return *selected;
}







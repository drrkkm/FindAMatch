
#include <Graph_lib/Regular_hexagon.h>
#include "cell.h"
#include <iostream>
#include "board.h"
#include "pictures.h"
using namespace Graph_lib;


Gameboard::Gameboard(Point xy, Graph_lib::Callback cb_clicked)
    : Widget{xy, lenghth, width, "Gameboard", nullptr} {

    Point t2{ 100, 250 };
    int starti = Cell::size;
    int startj = Cell::size;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++) {
            cells.push_back(new Cell{ t2, cb_clicked});
            t2.y +=60*sqrt(3);
        }
        t2.y -= 465;
        t2.x += 90;
        if (2 *i >= 2)
        {
            t2.y += 60*sqrt(3);
        }
    }
    t2.y -= 60*sqrt(3) - 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++) {
            cells.push_back(new Cell{ t2, cb_clicked});
            t2.y +=60*sqrt(3);
        }
        t2.y -= 465;
        t2.x += 90;
        if (2 *i >= 3)
        {
            t2.y += 60*sqrt(3);
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

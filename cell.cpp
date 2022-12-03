#include "cell.h"
#include "Regular_hexagon.h"
#include <string.h>
#include "cell.h"
#include "Graph_lib/Simple_window.h"
#include <string.h>
#include <stdexcept>

using namespace Graph_lib;

Cell::Cell (Point xy, Callback cb) : Button{ xy, size, size, "", cb }
{

}

void Cell::attach (Graph_lib::Window& win)
{
    Button::attach (win);
}


void Cell::activate (Graph_lib::Window &win, Point xy, std::string Picture_name)
{
    if (is_deleted) throw std::runtime_error("Cell was delete");
    Image move_counter {xy, Picture_name};
    win.attach(move_counter);
}

void Cell::deactivate (Graph_lib::Window &win, Point xy)
{
    if (!pw) throw std::runtime_error("Cell is not attached to a window");
    Graph_lib::Regular_hexagon tile(xy, 60);
    tile.set_fill_color(35);
    tile.set_color(224);
    win.attach(tile);
};
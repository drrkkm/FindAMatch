#include "cell.h"
#include <Graph_lib/Regular_hexagon.h>
#include <string.h>
#include "cell.h"
#include <string.h>
#include <stdexcept>
#include "utils.h"
#include <cmath>

using namespace Graph_lib;

Cell::Cell(Point xy, Graph_lib::Callback cb)
    : Button{ Point{xy.x - 38, xy.y - 36}, size + 6, size + 6, "", cb }
    , hex{new Regular_hexagon{xy, int(size/ 2* sqrt(3))}}
{
    //type = 1;
    hex->set_fill_color(35);
    hex->set_color(224);
}

void Cell::attach (Graph_lib::Window& win)
{
    Button::attach (win);
    reset_color();
    win.attach (*hex);
    DEBUG_OUT(&win);
    DEBUG_OUT(this);
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

void Cell::reset_color ()
{
  if (!pw) error ("Cell is not attached to a window");
    pw->color (Color::black);
}

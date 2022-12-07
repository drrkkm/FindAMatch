#include "cell.h"


using namespace Graph_lib;





Cell::Cell(Point xy, Graph_lib::Callback cb, int t)
    : Button{ Point{xy.x - 38, xy.y - 36}, size + 6, size + 6, "", cb}, type{t}
    , hex{new Regular_hexagon{xy, int(size/ 2* sqrt(3))}}
{
    picture p = picture();
    image = p.pictures1[type];
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


//void Cell::activate (Graph_lib::Window &win, Point xy, std::string Picture_name)
//{
//    if (is_deleted) throw std::runtime_error("Cell was delete");
//    Image move_counter {xy, Picture_name};
//    win.attach(move_counter);
//}

void Cell::activate (Graph_lib::Window &win)
{
    if (is_deleted) throw std::runtime_error("Cell was delete");
    try{
        auto *i = new Image(Point{center().x - 38, center().y - 38}, image, Suffix::png);

        win.attach(*i);
    }
    catch (std::exception& e){
        cerr << e.what();
    }
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

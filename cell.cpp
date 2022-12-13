#include "cell.h"


Cell::Cell(Graph_lib::Point xy, Graph_lib::Callback cb, int t)
    : Button{ Graph_lib::Point{xy.x - 38, xy.y - 36}, size + 6, size + 6, "", cb}, type{t}
    , hex{new Graph_lib::Regular_hexagon{xy, int(size/ 2* sqrt(3))}}
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

}

void Cell::activate (Graph_lib::Window &win)
{
    if (is_deleted) throw std::runtime_error("Cell was delete");
    try
    {
        Graph_lib::Point t = Graph_lib::Point{center().x - 38, center().y - 38};
        if (!pic_im)
        {
            pic_im = new Graph_lib::Image{t, image, Graph_lib::Suffix::png};
            win.attach(*pic_im);
        }
        else
        {
            pic_im1 = new Graph_lib::Image{t, image, Graph_lib::Suffix::png};
            win.attach(*pic_im1);
        }
    }
    catch (std::exception& e)
    {   
        std::cerr << e.what();
    }
}

void Cell::deactivate (Graph_lib::Window &win, Graph_lib::Point xy)
{
    if (!pw) throw std::runtime_error("Cell is not attached to a window");
    if (pic_im != nullptr)
    {
        win.detach(*pic_im);
        delete pic_im;
        pic_im = nullptr;
    }
    if (pic_im1 != nullptr)
    {
        win.detach(*pic_im1);
        delete pic_im1;
        pic_im1 = nullptr;}
}

void Cell::reset_color ()
{
    if (!pw) throw std::runtime_error("Cell is not attached to a window");
    pw->color (Graph_lib::Color::black);
}
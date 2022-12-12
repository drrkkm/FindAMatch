#ifndef CELL_H
#define CELL_H 1

#include <Graph_lib/GUI.h>
#include <Graph_lib/Regular_hexagon.h>
#include <string>
#include "pictures.h"
#include <stdexcept>
#include "utils.h"
#include <utility>
#include<memory>
#include <cmath>


using Graph_lib::Point;
using namespace Graph_lib;
struct Cell : Graph_lib::Button
{

    static constexpr int size = 70;
    int type;
    string image;
    bool is_deleted = false;

    Cell (Point xy, Graph_lib::Callback cb, int t);

    void attach (Graph_lib::Window& win) override;

    Point center() const {return Point{loc.x + width / 2, loc.y + height / 2};}

    //void activate(Graph_lib::Window &win, Point xy, std::string Picture_name);
    void activate(Graph_lib::Window &win, bool fl);

    void deactivate(Graph_lib::Window &win, Point xy);

    void reset_color ();
    unique_ptr<Image> update(Point xy)
    {
        unique_ptr<Image> p = unique_ptr<Image> (new Image{xy, image, Suffix::png});
        return p;

    }
    unique_ptr<Graph_lib::Regular_hexagon> update1(Point xy)
    {
        return unique_ptr<Graph_lib::Regular_hexagon> (new Graph_lib::Regular_hexagon{xy, 60});
    }



private:
   Graph_lib::Regular_hexagon *hex_im;
   unique_ptr<Graph_lib::Regular_hexagon> hex_im1;
   unique_ptr<Image> pic_im;
   unique_ptr<Image> pic_im1;
   bool opened = false;
   Graph_lib::Regular_hexagon* hex {nullptr};
};

#endif // #ifndef CELL_H

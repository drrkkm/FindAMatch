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

struct Cell : Graph_lib::Button
{

    static constexpr int size = 70;
    int type;
    bool is_deleted = false;

    Cell (Point xy, Graph_lib::Callback cb, int t);

    void attach (Graph_lib::Window& win) override;

    Point center() const {return Point{loc.x + width / 2, loc.y + height / 2};}

    //void activate(Graph_lib::Window &win, Point xy, std::string Picture_name);
    void activate(Graph_lib::Window &win);

    void deactivate(Graph_lib::Window &win, Point xy);

    void reset_color ();
    string image;


private:
    Graph_lib::Regular_hexagon* hex {nullptr};
};

#endif // #ifndef CELL_H

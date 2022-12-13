#ifndef CELL_H
#define CELL_H 1

#include <Graph_lib/GUI.h>
#include <Graph_lib/Regular_hexagon.h>
#include <string>
#include "pictures.h"


struct Cell : Graph_lib::Button
{
    static constexpr int size = 70;
    bool is_deleted = false;
    bool opened = false;
    int type;
    std::string image;

    Cell (Graph_lib::Point xy, Graph_lib::Callback cb, int t);
    
    ~Cell() 
    {   
        delete hex;
        delete pic_im1;
        delete pic_im;
    };

    Graph_lib::Point center() const {return Graph_lib::Point{loc.x + width / 2, loc.y + height / 2};}

    void attach (Graph_lib::Window& win) override;

    void activate(Graph_lib::Window &win);

    void deactivate(Graph_lib::Window &win, Graph_lib::Point xy);

    void reset_color ();

private:

    Graph_lib::Image* pic_im = nullptr;
    Graph_lib::Image* pic_im1 = nullptr;
    Graph_lib::Regular_hexagon* hex {nullptr};

};

#endif // #ifndef CELL_H

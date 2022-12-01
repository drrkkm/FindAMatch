#include <iostream>
#include "Graph_lib/Regular_hexagon.h"
#include "board.h"
#include "pictures.h"
using namespace Graph_lib;


Gameboard::Gameboard (Point xy, Graph_lib::Callback cb_clicked)
  : Widget{ xy, size, size, "Gameboard", nullptr }
{
  try
{
    Point t1{ 0, 0 };
    Point t2{ 100, 250 };
    Image move_counter {Point(0, 0), "move_counter.png"};
    Simple_window win{t1, 840, 639, "Find a pair cyberpunk"};
    Graph_lib::Rectangle rect(t1, 1200, 700);
    rect.set_fill_color(33);
    win.attach(rect);
    Graph_lib::Regular_hexagon a[32];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++) {
            Graph_lib::Regular_hexagon tilt(t2, 60);
            tilt.set_fill_color(35);
            tilt.set_color(224);
            a[i*4 + j] = tilt;
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
            Graph_lib::Regular_hexagon tilt(t2, 60);
            tilt.set_fill_color(35);
            tilt.set_color(224);
            a[12+i*4 + j] = tilt;
            t2.y +=60*sqrt(3);
        }
        t2.y -= 465;
        t2.x += 90;
        if (2 *i >= 3)
        {
            t2.y += 60*sqrt(3);
        }
    }
    for (int i = 0; i < 32; i++){
        win.attach(a[i]);
    }
    
    win.wait_for_button();
}
catch (std::exception& e)
{
    std::cerr << e.what() << std::endl;
}
catch (...) {
    std::cerr << "Oops, something went wrong..." << std::endl;
}

}


void Gameboard::show ()
{

}


void Gameboard::attach (Graph_lib::Window& win)
{
  for (int i = 0; i < cells.size(); ++i)
    win.attach (cells[i]);
  own = &win;
}


void Gameboard::select (Window &win, Cell& c)
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




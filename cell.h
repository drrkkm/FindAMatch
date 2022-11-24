#ifndef CELL_H
#define CELL_H 1

#include <Graph_lib/Simple_window.h>


using Graph_lib::Point;

struct Cell : Graph_lib::Button
{

  static constexpr int size = 100;


  Cell (Point xy, Graph_lib::Callback cb);

  void attach (Graph_lib::Window& win) override;

  void activate ();

  void deactivate ();

  Point center() const {return Point{loc.x + width / 2, loc.y + height / 2};}
};

#endif // #ifndef CELL_H

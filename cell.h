#ifndef CELL_H
#define CELL_H 1

#include "Graph_lib/Simple_window.h"


using namespace Graph_lib;
using Graph_lib::Point;

struct Cell : Graph_lib::Button
{

  static constexpr int size = 100;
  int type;
  bool is_deleted = false;

  Cell (Point xy, Graph_lib::Callback cb);

  void attach (Graph_lib::Window& win) override;

  void activate (Window &win, Point xy, std::string Picture_name);

  void deactivate (Window &win, Point xy);

  Point center() const {return Point{loc.x + width / 2, loc.y + height / 2};}
};

#endif // #ifndef CELL_H

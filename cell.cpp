#include "cell.h"

using namespace Graph_lib;


Cell::Cell (Point xy, Callback cb)
  : Button{ xy, size, size, "", cb }

{
  /* All done */
}

void Cell::attach (Graph_lib::Window& win)
{
  Button::attach (win);
}



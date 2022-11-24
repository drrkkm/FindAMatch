#include <iostream>

#include "board.h"

using namespace Graph_lib;


//Cell::Type type_of_cell (int i, int j)
//{
//  if (i % 2 == 0)
//    return (j % 2 == 0) ? Cell::black : Cell::white;
//  else
//    return (j % 2 == 0) ? Cell::white : Cell::black;
//}


Gameboard::Gameboard (Point xy, Graph_lib::Callback cb_clicked)
  : Widget{ xy, size, size, "Gameboard", nullptr }
{}


void Gameboard::show ()
{}


void Gameboard::attach (Graph_lib::Window& win)
{}


void Gameboard::select (Cell& c)
{}


Cell& Gameboard::at (char c, int i){
}


auto Gameboard::where(Cell& c) const -> Position
{
}



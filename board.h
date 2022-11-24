#ifndef BOARD_H
#define BOARD_H

#include "cell.h"


using Graph_lib::Point;
using Graph_lib::Address;


struct Gameboard : Graph_lib::Widget
{
  static constexpr int N = 4;
  static constexpr int count_cells = 32;
  static constexpr int size = 10;

  Gameboard (Point xy, Graph_lib::Callback cb_clicked);

  using Position = std::pair<char, int>;

  void show () override;

  bool check_pair_cells();

  void attach (Graph_lib::Window& win) override;

  Cell& at (char c, int i);

  Position where (Cell& c) const;

  bool has_selected () const {return selected != nullptr;}

  Cell& get_selected ();

  void select (Cell& c); // toggle selection

private:
  Graph_lib::Vector_ref<Cell> cells;

  Cell* selected{ nullptr };               // activated cell
};
#endif // #ifndef BOARD_H
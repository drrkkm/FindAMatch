#ifndef BOARD_H
#define BOARD_H

#include "cell.h"


using Graph_lib::Point;
using Graph_lib::Address;


struct Gameboard : Graph_lib::Widget
{
  static constexpr int N = 4;
  static constexpr int count_cells = 32;
  static constexpr int size = 100;

  Gameboard (Point xy, Graph_lib::Callback cb_clicked);

  using Position = std::pair<char, int>;

  void show () override; // отрисовка поля
 
  //bool check_pair_cells(); //  проверка двух селлов на совпадение

  void attach (Graph_lib::Window& win) override; // привязка всех селлов к окну

  bool has_selected () const {return selected != nullptr;} 

  Cell& get_selected (); // так же как и в шашках

  void select (Window &win, Cell& c); // логика открытия двух фишек

private:
  Graph_lib::Vector_ref<Cell> cells;

  Cell* selected{ nullptr };               // activated cell
};
#endif // #ifndef BOARD_H

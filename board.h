#ifndef BOARD_H
#define BOARD_H

#include "cell.h"
#include <Graph_lib/Regular_hexagon.h>
#include <iostream>
#include <random>
#include "pictures.h"

using Graph_lib::Point;
using Graph_lib::Address;


struct Gameboard : Graph_lib::Widget
{
    static constexpr int N = 4;
    static constexpr int count_cells = 32;
    static constexpr int lenghth = 840;
    static constexpr int width = 639;

    Gameboard (Point xy, Graph_lib::Callback cb_clicked);

    using Position = std::pair<char, int>;

    void show (Graph_lib::Window& win);
    void draw_pole(Graph_lib::Window& win);

    bool check_pair_cells();

    void attach (Graph_lib::Window& win) override;
    bool has_selected () const {return selected != nullptr;}
    std::vector<int> r_gen_int_n();
    Graph_lib::Vector_ref<Cell> cells;
    //Graph_lib::Vector_ref<Cell> give_cells();
    Cell& get_selected ();

private:

    Cell* selected{ nullptr };               // activated cell
    void select(Graph_lib::Window &win, Cell &c);
};

#endif // #ifndef BOARD_H

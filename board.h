#ifndef BOARD_H
#define BOARD_H

#include "cell.h"
#include <Graph_lib/Regular_hexagon.h>
#include <iostream>
#include <random>
#include "pictures.h"

using Graph_lib::Address;


struct Gameboard : Graph_lib::Widget
{
    static constexpr int N = 4;
    static constexpr int count_cells = 32;
    static constexpr int lenghth = 840;
    static constexpr int width = 639;

    Gameboard (Graph_lib::Point xy, Graph_lib::Callback cb_clicked);
    ~Gameboard() 
    {
        cells.clear();
        delete rect;
        delete move_counter;
    };

    using Position = std::pair<char, int>;

    void attach_game (Graph_lib::Window& win, bool t);

    void attach (Graph_lib::Window& win) override;
    bool has_selected () const {return selected != nullptr;}
    std::vector<int> r_gen_int_n();
    Graph_lib::Vector_ref<Cell> cells;

    Cell& get_selected ();

private:

    Cell* selected{ nullptr };

    Graph_lib::Rectangle *rect = new Graph_lib::Rectangle(Graph_lib::Point(0, 0), 1200, 700);
    Graph_lib::Image *move_counter = new Graph_lib::Image{Graph_lib::Point(0, 0), "./pictures/move_counter.png", Graph_lib::Suffix::png};
};

#endif // #ifndef BOARD_H

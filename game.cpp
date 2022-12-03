#include "game.h"
#include "Graph_lib/board.h"
#include "Graph_lib/Regular_hexagon.h"
#include "Graph_lib/cell.h"
#include <iostream>
using namespace Graph_lib;

Game::Game(Point xy)
        : Window{Point(0, 0), 840, 639, "Find a pair cyberpunk"}, board{Point{0, 0}, cb_clicked} {
    size_range(Gameboard::size, Gameboard::size,
               Gameboard::size, Gameboard::size);
    Point t1{ 0, 0 };
    Point t2{ 100, 250 };
    Graph_lib::Image move_counter {Point(0, 0), "move_counter.png"};
    Graph_lib::Rectangle rect(t1, 1200, 700);

    rect.set_fill_color(33);
    this->attach(rect);
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
    Graph_lib::Vector_ref<Cell>all_cells = this->board.give_cells();
    std::cout << all_cells.size();
    for (int i = 0; i < 32; i++){
        this->attach(a[i]);
        this->attach(all_cells[i]);
    }
    this->attach(move_counter);

//        cell.attach(win);
    Cell cell{Point{10, 10}, cb_clicked};
    Cell cell1{Point{100, 10}, cb_clicked};
    this->attach(cell);
    this->attach(cell1);
    this->wait_for_expose();
}
void Game::clicked(Cell& c)
{
    if (board.has_selected()) {
        Cell &selected_cell = board.get_selected();
        if (board.get_selected().type != c.type) {
            selected_cell.deactivate(*this, selected_cell.center());
            c.deactivate(*this, c.center());
        }
    }
    if (board.get_selected().type == c.type) {
        // something
    }
    Fl::redraw();
}
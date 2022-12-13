#include "board.h"
#include <algorithm>


std::ostream& operator << (std::ostream& os, std::vector<int> vec){
    for (int i : vec){
        os << i << " ";
    }
    return os;
}


Gameboard::Gameboard(Graph_lib::Point xy, Graph_lib::Callback cb_clicked)
    : Widget{xy, lenghth, width, "Gameboard", nullptr} {
    std::vector<int> pictures_number = r_gen_int_n();
    int counter = 0;
    Graph_lib::Point t2{ 100, 250 };
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++) {
            
            cells.push_back(new Cell{ t2, cb_clicked, pictures_number[counter]});
            ++counter;
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
            cells.push_back(new Cell{ t2, cb_clicked, pictures_number[counter]});
            ++counter;
            t2.y +=60*sqrt(3);
        }
        t2.y -= 465;
        t2.x += 90;
        if (2 *i >= 3)
        {
            t2.y += 60*sqrt(3);
        }
    }
}

void Gameboard::attach (Graph_lib::Window& win)
{
    for (int i = 0; i < cells.size(); ++i)
        win.attach(cells[i]);
    own = &win;
}

void Gameboard::attach_game (Graph_lib::Window& win, bool t)
{   
    if (t)
    {
        rect->set_fill_color(33);
        win.attach(*rect);
        win.attach(*move_counter);
    }
    else
    {
        auto *x = new Graph_lib::Text (Graph_lib::Point (200 , 200) ,"YOU WIN") ;
        x->set_color (Graph_lib::Color::blue);
        win.attach(*x);
    }
    own = &win;
}


Cell& Gameboard::get_selected()
{
    if (!selected) throw std::runtime_error ("Gameboard::get_selected(): none of cells is selected");
    return *selected;
}


std::vector<int> Gameboard::r_gen_int_n()
{
    std::vector<int> pictures_number(32);

    for (int i = 0; i < pictures_number.size(); ++i)
    {
        pictures_number[i] = i + 1;
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(pictures_number.begin(), pictures_number.end(), g);

    for (int i = 0; i < pictures_number.size(); ++i)
    {
        if (pictures_number[i] >= 16)
            pictures_number[i] %= 16;
    }
    return pictures_number;
}


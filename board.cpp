#include "board.h"

using namespace Graph_lib;
using namespace std;

ostream& operator << (ostream& os, vector<int> vec){
    for (int i : vec){
        os << i << " ";
    }
    return os;
}


Gameboard::Gameboard(Point xy, Graph_lib::Callback cb_clicked)
    : Widget{xy, lenghth, width, "Gameboard", nullptr} {
    vector<int> pictures_number = r_gen_int_n();
    int c = 0;
    Point t2{ 100, 250 };
    int starti = Cell::size;
    int startj = Cell::size;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++) {
            cells.push_back(new Cell{ t2, cb_clicked, pictures_number[c]});
            ++c;
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
            cells.push_back(new Cell{ t2, cb_clicked, pictures_number[c]});
            ++c;
            t2.y +=60*sqrt(3);
        }
        t2.y -= 465;
        t2.x += 90;
        if (2 *i >= 3)
        {
            t2.y += 60*sqrt(3);
        }
    }
    cout << pictures_number;
}

void Gameboard::attach (Graph_lib::Window& win)
{
    for (int i = 0; i < cells.size(); ++i)
        win.attach(cells[i]);

    own = &win;
}


void Gameboard::select (Graph_lib::Window &win, Cell& c)
{
//    std::cerr<<"bbb";
//    if (selected)
//        selected->deactivate(win, c.center());

//    if (selected != &c)
//    {
//        selected = &c;
//        selected->activate(win, c.center(), pictures[c.type]);
//    }
//    else
//        selected = nullptr;
}


Cell& Gameboard::get_selected()
{
    std::cerr<<"aaa";
    if (!selected)
        error ("Gameboard::get_selected(): none of cells is selected");

    return *selected;
}


vector<int> Gameboard::r_gen_int_n(){
    vector<int> pictures_number(32);

    for (int i = 0; i < pictures_number.size(); ++i) {
        pictures_number[i] = i + 1;
    }
    random_device rd;
    mt19937 g(rd());
    shuffle(pictures_number.begin(), pictures_number.end(), g);

    for (int i = 0; i < pictures_number.size(); ++i) {
        if (pictures_number[i] >= 16)
            pictures_number[i] %= 16;
    }
    return pictures_number;
}


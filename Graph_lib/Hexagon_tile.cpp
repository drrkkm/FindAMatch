#include "Hexagon_tile.h"

namespace Graph_lib {
    Hexagon_tile::Hexagon_tile(Point p, int ww, int hh, int radius): Rectangle(p, ww, hh) {
        Regular_hexagon h{Point{0, 0}, radius};

        const int x_max = point(0).x + width() - h.width() / 2;
        const int y_max = point(0).y + height()  - h.height() / 2;
        const int dx = h.width() + h.edge();
        const int dy = h.height() / 2;

        int y = point(0).y + dy;
        for (int i = 0; y <= y_max; ++i, y += dy) {
            int x = point(0).x + h.width() / 2;
            if (i % 2)
                x += dx / 2;

            for (; x <= x_max; x += dx) {
                tile.push_back(new Regular_hexagon{Point{x, y}, radius});
                tile[tile.size() - 1].set_fill_color(Color(35));
                tile[tile.size() - 1].set_color(Color::cyan);
            }
        }
        set_color(Color::invisible);
    }

    void Hexagon_tile::move(int dx, int dy) {
        Rectangle::move(dx, dy);
        for (int i = 0; i < tile.size(); ++i)
            tile[i].move(dx, dy);
    }

    void Hexagon_tile::draw_lines() const {
        Rectangle::draw_lines();

        for (int i = 0; i < tile.size(); ++i)
            tile[i].draw();
    }
}

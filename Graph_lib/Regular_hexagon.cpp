//
// Created by sibenshtern on 01.11.22.
//
#include <cmath>

#include "Point.h"
#include "vec2d.h"

#include "Regular_hexagon.h"

namespace Graph_lib {
    Regular_hexagon::Regular_hexagon(Point center, int radius) {
        constexpr int n = 6;

        for (int i = 0; i < n; ++i) {
            Point p;
            double phi = 2 * pi * i / n;

            p.x = center.x + round(radius * cos(phi));
            p.y = center.y + round(radius * sin(phi));

            add(p);
        }
    }

    int Regular_hexagon::width() const {
        return abs(point(0).x - point(3).x);
    }
    int Regular_hexagon::height() const {
        return abs(point(1).y - point(5).y);
    }
    int Regular_hexagon::edge() const {
        return abs(point(1).x - point(2).x);
    }
    Point Regular_hexagon::center() const {
        return Point{(point(0).x + point(3).x) / 2, point(0).y};
    }

//    Regular_hexagon::Regular_hexagon(const Regular_hexagon hexagon) {
//
//    }
}


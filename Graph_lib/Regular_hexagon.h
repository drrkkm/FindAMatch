//
// Created by sibenshtern on 01.11.22.
//

#ifndef GRAPHICS_REGULAR_HEXAGON_H
#define GRAPHICS_REGULAR_HEXAGON_H

#include "Graph.h"

namespace Graph_lib {
    struct Regular_hexagon: Polygon {
        using Polygon::Polygon;

        Regular_hexagon( Point center, int radius);
        Point center() const;
        int width() const;
        int height() const;
        int edge() const;
    };
}

#endif //GRAPHICS_REGULAR_HEXAGON_H

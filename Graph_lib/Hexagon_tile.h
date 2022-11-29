//
// Created by sibenshtern on 01.11.22.
//

#ifndef GRAPHICS_HEXAGON_TILE_H
#define GRAPHICS_HEXAGON_TILE_H

#include "Graph.h"
#include "Regular_hexagon.h"

namespace Graph_lib {
    struct Hexagon_tile: Rectangle {
        Hexagon_tile(Point p, int width, int height, int radius);

        void move(int dx, int dy) override;

    protected:
        void draw_lines() const override;

    private:
        Vector_ref<Regular_hexagon> tile;
    };
}


#endif //GRAPHICS_HEXAGON_TILE_H

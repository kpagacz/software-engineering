#include "Tile.h"

#include <iostream>

std::ostream& operator<<(std::ostream& out, const Tile& tile) {
    tile.print(out);
    return out;
}

void ColoredTile::print(std::ostream& out) const {
    if (color)
        #ifdef _WIN32
        out << "0";
        #else
        out << "\u25a1";
        #endif
    else
        #ifdef _WIN32
        out << "1";
        # else
        out << "\u25a0";
        #endif
}

void ColoredTile::flip_color() {
    color = !color;
}

bool& ColoredTile::get_color() {
    return color;
}



#include "Ant.h"
#include <iostream>
#include <stdexcept>

// Ant
void Ant::print(std::ostream& out) const {
    out << "M";
}

Ant::Ant(char _direction, bool _color): Tile() {
    if(_direction == 'N' || _direction == 'S' || _direction == 'E' || _direction == 'W')
        direction = _direction;
    else 
        throw std::invalid_argument("_direction must be N, S, E or W");

    tile = nullptr;
}

void Ant::change_direction(char new_dir) {
    if(new_dir == 'N' || new_dir == 'S' || new_dir == 'E' || new_dir == 'W')
        direction = new_dir;
    else
        throw std::invalid_argument("new_dir must be N, S, E or W");
}

char& Ant::get_direction() {
    return direction;
}

void Ant::move_procedure() {
    if(tile) {
        // change direction
        char directions[] = {'N', 'E', 'S', 'W'};
        int curr_dir = 0;
        while(directions[curr_dir] != direction) curr_dir++;
        if(tile->get_color())
            curr_dir = (curr_dir + 4 - 1) % 4;
        else
            curr_dir = (curr_dir + 1) % 4;
        direction = directions[curr_dir];

        // flip color
        tile->flip_color();
    }
}

Tile*& Ant::get_tile() {
    return tile;
}

void Ant::flip_color() {
    tile->flip_color();
}

bool& Ant::get_color() {
    return tile->get_color();
}

// LangtonAnt
LangtonAnt::LangtonAnt(int _size) {
    board = new Board_tp<Tile>(_size, _size);
    for(int i = 0; i < _size; i++)
        for(int j = 0; j < _size; j++)
            board->get_position(i, j) = new ColoredTile;

    ant_position = std::pair<int, int>(_size / 2, _size / 2);
    ant = new Ant;
    ant->get_tile() = board->get_position(ant_position);
    board->get_position(ant_position) = ant;
    size = _size;
}

LangtonAnt::~LangtonAnt() {
    board->get_position(ant_position) = ant->get_tile();
    delete board;
}

std::ostream& operator<<(std::ostream& out, const LangtonAnt& la) {
    la.print(out);
    return out;
}

void LangtonAnt::print(std::ostream& out) const {
    out << *board;
}

bool LangtonAnt::cycle() {
    ant->move_procedure();

    char ant_dir = ant->get_direction();
    switch(ant_dir) {
        case 'N':
            if(validate_coords(ant_position.first - 1, ant_position.second))
                move_ant(std::make_pair(ant_position.first - 1, ant_position.second));
            else 
                return false;
            break;
        case 'E':
            if(validate_coords(ant_position.first, ant_position.second + 1))
                move_ant(std::make_pair(ant_position.first, ant_position.second + 1));
            else
                return false;
            break;
        case 'S':
            if(validate_coords(ant_position.first + 1, ant_position.second))
                move_ant(std::make_pair(ant_position.first + 1, ant_position.second));
            else
                return false;
            break;
        case 'W':
            if(validate_coords(ant_position.first, ant_position.second - 1))
                move_ant(std::make_pair(ant_position.first, ant_position.second - 1));
            else
                return false;
            break;
    }
    return true;
}

bool LangtonAnt::validate_coords(const int& x, const int& y) {
    return (x >= 0 && x < size && y >= 0 && y < size);
}

void LangtonAnt::move_ant(std::pair<int, int> new_coords) {
    board->get_position(ant_position) = ant->get_tile();
    ant->get_tile() = board->get_position(new_coords);
    board->get_position(new_coords) = ant;
    ant_position = new_coords;
}

void LangtonAnt::find_Langton() {
    bool can_continue = true;
    do
    {
        if (system("CLS")) system("clear");
        std::cout << "Press enter to keep looking for Langton\n";
        print(std::cout);
        can_continue = cycle();
    } while (getchar() && can_continue);
}
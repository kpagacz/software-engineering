#ifndef ANT__
#define ANT__

#include "Tile.h"
#include "Board_tp.h"
#include <iostream>

class Ant : virtual public Tile{
public:
    Ant(char _direction = 'W', bool _color = false);
    ~Ant() = default;;

    void change_direction(char new_dir);
    char& get_direction();
    void move_procedure();
    Tile*& get_tile();
    void flip_color();
    bool& get_color();
private:
    char direction;
    Tile* tile;
    void print(std::ostream&) const;
};

class LangtonAnt {
public:
    LangtonAnt(int size);
    ~LangtonAnt();

    friend std::ostream& operator<<(std::ostream& out, const LangtonAnt& la);
    bool cycle();
    void find_Langton();
private:
    int size;
    Board_tp<Tile> *board;
    std::pair<int, int> ant_position;
    Ant* ant;
    void print(std::ostream&) const;
    void move_ant(std::pair<int, int> new_coords);
    bool validate_coords(const int& x, const int& y);
};


#endif // ANT__
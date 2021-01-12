#ifndef TILE__
#define TILE__

#include <iostream>

class Tile{
public:
    Tile() = default;
    virtual ~Tile() = default;
    friend std::ostream& operator<<(std::ostream&, const Tile&);
    virtual void flip_color() = 0;
    virtual bool& get_color() = 0;
private:
    virtual void print(std::ostream&) const = 0;
};

class ColoredTile : virtual public Tile {
public:
    ColoredTile(bool _color = false) : Tile(), color(_color) {}
    ~ColoredTile() = default;
    void flip_color();
    bool& get_color();
private:
    void print(std::ostream&) const;
    bool color;
};

#endif // TILE__
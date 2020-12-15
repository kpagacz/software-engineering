#ifndef CELL
#define CELL

#include <iostream>

class Cell {
private:
	bool alive;
public:
	Cell(bool _alive) : alive(_alive) {}
	virtual ~Cell() = default;
	
	bool& getAlive() { return alive; }

	friend std::ostream& operator<<(std::ostream& out, const Cell& c) {
		out << ((c.alive) ? 'o' : '.');
		return out;
	}
};
#endif // CELL

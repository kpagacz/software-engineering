#ifndef CELLS_BOARD
#define CELLS_BOARD

#include "Board_tp.h"
#include "Cell.h"
#include <iostream>

class CellsBoard
{
public:
	CellsBoard(int _width, int _height);
	~CellsBoard();

	void print(std::ostream& out);
	int get_cycle();
	void next_cycle();
private:
	Board_tp<Cell> *board;
	int width, height, cycle;
	bool validate_x_y(const int&, const int&) const;
};

#endif // CELLS_BOARD
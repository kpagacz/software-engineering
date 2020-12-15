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
private:
	Board_tp<Cell> *board;
	int width, height;
};

#endif // CELLS_BOARD
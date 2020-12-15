#include "Board_tp.h"
#include "Cell.h"
#include "CellsBoard.h"

#include <iostream>

int main() {
	Board_tp<int> b(2, 2);
	Board_tp<Cell> board_cells(10, 10);

	b.print(std::cout);

	CellsBoard cells(5, 5);
	cells.print(std::cout);

	return 0;
}
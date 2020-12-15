#include "CellsBoard.h"
#include <stdio.h>

CellsBoard::CellsBoard(int _width, int _height)
{
	width = _width;
	height = _height;
	board = new Board_tp<Cell>(width, height);

	srand(0);
	for (int i = 1; i < width - 1; i++) 
		for (int j = 1; j < height - 1; j++) 
			board->get_position(i, j) = new Cell(rand() % 2);
}

CellsBoard::~CellsBoard()
{
	delete board;
}

void CellsBoard::print(std::ostream& out)
{
	board->print(out);
}

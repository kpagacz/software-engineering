#include "CellsBoard.h"
#include <stdio.h>
#include <ctime>

CellsBoard::CellsBoard(int _width, int _height)
{
	width = _width;
	height = _height;
	cycle = 0;
	board = new Board_tp<Cell>(width, height);

	srand(time(NULL));
	for (int i = 0; i < width; i++) 
		for (int j = 0; j < height; j++) 
			board->get_position(i, j) = new Cell(rand() % 2);
}

CellsBoard::~CellsBoard()
{
	delete board;
}

void CellsBoard::print(std::ostream& out)
{
	std::cout << "Cell cycle: " << cycle << "\n";
	board->print(out);
}

int CellsBoard::get_cycle()
{
	return cycle;
}

void CellsBoard::next_cycle()
{
	bool* change_state = new bool[long long(width) * height];
	
	for (int i = 0; i < height; i++) 
		for (int j = 0; j < width; j++) {
		// counting alive neighbours of every cell
		int alive_neighbours = -1 * board->get_position(i, j)->getAlive();
		for (auto k : { -1, 0, 1 })
			for (auto l : { -1, 0, 1 }) {
				int _x = i + k;
				int _y = j + l;
				if (validate_x_y(_x, _y)) 
					alive_neighbours += board->get_position(_x, _y)->getAlive();
			}

		// setting a flag indicating whether to flip the state of cell or not
		if (board->get_position(i, j)->getAlive()) {
			if (alive_neighbours < 2 || alive_neighbours > 3)
				change_state[i * width + j] = true;
			else
				change_state[i * width + j] = false;
		}
		else {
			if (alive_neighbours == 3)
				change_state[i * width + j] = true;
			else
				change_state[i * width + j] = false;
		}
	}

	// flipping cell states according to flags in change_state
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if (change_state[i * width + j]) 
				board->get_position(i, j)->getAlive() = !board->get_position(i, j)->getAlive();

	cycle++;
}

bool CellsBoard::validate_x_y(const int& x, const int& y) const
{
	return (x >= 0) && (x < height) && (y >= 0) && (y < width);
}

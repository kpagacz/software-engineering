#include "Board.h"

Board::Board(const int& _width, const int& _height)
{
}

Board::~Board()
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			delete board[i][j];
		}
		delete[] board[i];
	}
	delete[] board;
}

void Board::insert(const int& _x, const int& _y, Type t)
{
	if (board[_x][_y]) delete board[_x][_y];

	switch (t) {
	case Type::A: board[_x][_y] = new A; break;
	case Type::B: board[_x][_y] = new B; break;
	case Type::C: board[_x][_y] = new C; break;
	case Type::D: board[_x][_y] = new D; break;
	}
}

std::ostream& operator<<(std::ostream& out, const Board& b)
{
	for (int i = 0; i < b.width; i++) {
		for (int j = 0; j < b.height; j++) {
			if (b.board[i][j]) b.board[i][j]->print();
		}
	}
	return out;
}

#include "Board.h"

Board::Board(const int& _width, const int& _height)
{
	width = _width;
	height = _height;

	board = new Object**[height];
	for (int i = 0; i < height; i++) {
		board[i] = new Object * [width];
		for (int j = 0; j < width; j++) board[i][j] = nullptr;
	}
}

Board::~Board()
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			delete board[i][j];
		}
		delete[] board[i];
	}
	delete[] board;
}

void Board::insert(const int& _x, const int& _y, const char t)
{
	if (!validate_x_y(_x, _y)) return;

	if (board[_x][_y]) delete board[_x][_y];
	board[_x][_y] = nullptr;

	switch (t) {
	case 'A': board[_x][_y] = new A; break;
	case 'B': board[_x][_y] = new B; break;
	case 'C': board[_x][_y] = new C; break;
	case 'D': board[_x][_y] = new D; break;
	}
}

void Board::exchange(const int& x1, const int& y1, const int& x2, const int& y2)
{
	if (!validate_x_y(x1, y1) || !(validate_x_y(x2, y2))) return;

	Object* temp = board[x1][y1];
	board[x1][y1] = board[x2][y2];
	board[x2][y2] = temp;
}

void Board::move(const int& x, const int& y, const int& x_move, const int& y_move)
{
	if(!validate_x_y(x, y) || !validate_x_y(x + x_move, y + y_move)) return;

	delete board[x + x_move][y + y_move];
	board[x + x_move][y + y_move] = nullptr;
	board[x + x_move][y + y_move] = board[x][y];

	board[x][y] = nullptr;
}

void Board::clear_board()
{
	for (int i = 0; i < height; i++) for (int j = 0; j < width; j++) {
		delete board[i][j];
		board[i][j] = nullptr;
	}
}

bool Board::validate_x_y(const int& x, const int& y) const
{
	return (x >= 0) && (x < height) && (y >= 0) && (y < width);
}

std::ostream& operator<<(std::ostream& out, const Board& b)
{
	for (int i = 0; i < b.height; i++) {
		for (int j = 0; j < b.width; j++) {
			if (b.board[i][j]) b.board[i][j]->print(out); else out << ".";
		}
		out << "\n";
	}
	out << "\n";

	return out;
}

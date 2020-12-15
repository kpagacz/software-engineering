#ifndef BOARD
#define BOARD

#include "Object.h"
#include<iostream>

class Board
{
public:
	Board(const int& _width, const int& _height);
	~Board();
	void insert(const int& _x, const int& _y, const char t);
	void exchange(const int&, const int&, const int&, const int&);
	void move(const int&, const int&, const int&, const int&);
	void clear_board();
	friend std::ostream& operator<<(std::ostream& out, const Board& b);
private:
	Object** *board;
	int width, height;
	bool validate_x_y(const int&, const int&) const;

};

#endif // BOARD
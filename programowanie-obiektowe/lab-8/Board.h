#pragma once
#include "Object.h"
#include<iostream>

enum Type { A, B, C, D };

class Board
{
public:
	Board(const int& _width, const int& _height);
	~Board();
	void insert(const int& _x, const int& _y, Type t);
	friend std::ostream& operator<<(std::ostream& out, const Board& b);
private:
	Object*** board;
	int width, height;
};


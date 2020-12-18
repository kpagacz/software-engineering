#include "CellsBoard.h"

#include <iostream>

int main() {
	int width, height, cycles;
	std::cout << "Input the width and height of the board with cells: ";
	std::cin >> width >> height;
	CellsBoard b(width, height);

	std::cout << "Input the number of cycles to perform: ";
	std::cin >> cycles;

	for (int i = 0; i < cycles; i++) {
		b.print(std::cout);
		b.next_cycle();
	}
	b.print(std::cout);

	return 0;
}
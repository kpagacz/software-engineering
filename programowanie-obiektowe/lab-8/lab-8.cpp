#include "Object.h"
#include "Board.h"

#include<iostream>


int main() {
	Board b(10, 10);
	std::cout << b << "\n\n";

	b.insert(0, 0, 'A');
	b.insert(3, 2, 'B');
	b.insert(9, 8, 'C');
	b.insert(2, 7, 'D');
	std::cout << b << "\n\n";

	b.exchange(0, 0, 3, 2);
	b.exchange(9, 8, 9, 0);
	std::cout << b << "\n\n";

	b.move(0, 0, 1, 1);
	std::cout << b << "\n\n";
	return 0;
}
#include "Ciag.h"

#include<iostream>

int main() {
	Ciag c1;
	std::cout << c1 << "\n";
	std::cout << c1 << "\n";

	Ciag c2(2, 1, 5);
	++c2;
	std::cout << c2 << "\n";

	Ciag c3(c2);
	std::cout << c3 << "\n";

	return 0;
}
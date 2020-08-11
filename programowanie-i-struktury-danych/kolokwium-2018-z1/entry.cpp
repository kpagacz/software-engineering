#include <iostream>
#include "rope.h"


int main() {
	Rope r1;

	for (int i : {1, 3, 6, 1, 3, 7, 2, 6, 3, 1, 1}) {
		r1.insert(i);
	}

	r1.print();
	r1.funny_remove(7);
	r1.print();

	Rope r2;

	for (int i : {9, 9, 9, 8, 8, 6, 6, 6, 6, 5, 5, 5, 5, 2, 2, 1, 1}) {
		r2.insert(i);
	}

	r2.print();
	r2.funny_move();
	r2.print();

	Rope r3, r4;
	for (int i : {7, 7, 6, 5, 4, 4, 4, 4, 3, 2, 2}) {
		r3.insert(i);
	}

	for (int i : {8, 8, 6, 6, 6, 5, 4, 4, 2, 2 }) {
		r4.insert(i);
	}

	r3.print();
	r4.print();
	r3.exchangeConstantVectors2(r4);
	r3.print();
	r4.print();

	Rope r5, r6;
	for (int i : {5, 5}) {
		r5.insert(i);
	}

	for (int i : {9, 8, 7, 6, 1}) {
		r6.insert(i);
	}

	r5.exchangeConstantVectors2(r6);
	r5.print();
	r6.print();

	Rope* ptr1 = new Rope, *ptr2 = new Rope;
	Rope* arr[] = { ptr1, ptr2 };
	for (Rope* r : arr) {
		std::cout << "Rope!\n";
	}
	return 0;
}
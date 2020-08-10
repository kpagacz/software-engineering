#include<iostream>
#include "rope.hpp"


int main() {
	Rope r1;

	for (int i : {4, 7, 5, 1, 6, 6, 1, 7, 7, 3, 2, 1, 2, 3, 1}) {
		r1.insert(i);
	}

	r1.print();

	r1.funny_remove(2, 3);
	r1.print();

	Rope r2;
	for (int i : {3, 3, 3, 9, 1, 8, 8, 6, 6, 4, 4, 4, 4, 4, 3, 2, 2, 1, 1}) {
		r2.insert(i);
	}

	r2.print();
	r2.move();
	r2.print();


	Rope r3;
	Rope r4;
	for (int i : {3, 6, 6, 1, 4, 2, 4, 5, 3, 2, 1}) {
		r3.insert(i);
	}

	for (int i : {3, 8, 6, 4, 6, 5, 2, 4, 1, 2}) {
		r4.insert(i);
	}

	r3.print();
	r4.print();

	r3.move_pairs(r4, 2);
	r3.print();
	r4.print();
	return 0;
}
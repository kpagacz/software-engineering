#include <iostream>
#include "rope.h"


int main() {
	Rope r1;
	for (int i : {4, 7, 5, 1, 6, 6, 7, 1, 4, 2, 9, 1, 1}) {
		r1.insert(i);
	}
	r1.print();

	r1.funny_remove(3);
	r1.print();

	Rope r2;
	for (int i : {3, 6, 6, 4, 7, 5, 7, 3, 2, 9, 7, 7, 4, 2}) {
		r2.insert(i);
	}

	r2.print();
	r2.moveThrees();
	r2.print();


	Rope r3, r4;
	for (int i : {1, 2, 7, 7, 1, 3, 2, 4, 5}) {
		r3.insert(i);
	}

	for (int i : {3, 2, 3, 6, 3, 4, 8, 6, 5, 6, 2}) {
		r4.insert(i);
	}

	r3.print();
	r4.print();
	r3.exchangePairs(r4);
	r3.print();
	r4.print();
	return 0;
}
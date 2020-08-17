#include<iostream>
#include "rope.h"


int main() {
	Rope r1;
	for (int i : {1, 3, 6, 1, 3, 7, 2, 6, 3, 1, 1}) {
		r1.insert(i);
	}

	r1.print();
	r1.funny_remove();
	r1.print();

	Rope r2;
	for (int i : {1, 1, 2, 2, 5, 5, 5, 5, 6, 6, 6, 8, 8, 9, 9, 9}) {
		r2.insert(i);
	}

	r2.print();
	r2.moveWithStep(20);
	r2.print();


	Rope r3, r4;
	for (int i : {1, 2, 2, 4, 4, 4, 4, 5, 6, 6, 7}) {
		r3.insert(i);
	}
	for (int i : {2, 2, 3, 3, 3, 4, 6, 6, 6, 8, 8}) {
		r4.insert(i);
	}

	r3.print();
	r4.print();
	r3.exchangeGroups(r4);
	r3.print();
	r4.print();

	Rope r5, r6;
	for (int i : {2, 2}) {
		r5.insert(i);
	}
	for (int i : {1, 3, 5}) {
		r6.insert(i);
	}
	r5.print();
	r6.print();
	r5.exchangeGroups(r6);
	r5.print();
	r6.print();
	return 0;
}
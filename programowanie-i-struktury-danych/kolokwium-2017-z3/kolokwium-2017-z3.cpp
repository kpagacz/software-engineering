#include<iostream>
#include"sznur.h"

int main() {
	// Zad 1
	std::cout << "ZAD 1:\n";
	sznur s1;
	for (int i : {1, 3, 6, 1, 3, 7, 2, 6, 3, 1, 1}) {
		s1.wstaw(i);
	}

	s1.wypisz();
	usun(s1);
	s1.wypisz();

	sznur s2;
	for (int i : {7, 5, 5, 5, 4, 4, 4, 2, 1}) {
		s2.wstaw(i);
	}
	s2.wypisz();
	usun(s2);
	s2.wypisz();
	return 0;
}

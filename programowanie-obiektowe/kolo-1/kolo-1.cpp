#include <iostream>

#include "Koszyk.h"

int main() {
	Koszyk k1;
	Produkt* p1 = new Jedzenie("bulka bezglutenowa", 1, true);
	Produkt* p2 = new Chemia("plyn do podlog", 2, true);
	
	// adding elements
	std::cout << "Testowanie dodawania elementow:\n";
	k1 + p1 + p2;
	std::cout << k1;

	// removing elements
	std::cout << "Testowanie usuwania elementow:\n";
	k1.zwroc("bulka bezglutenowa");
	std::cout << k1;
	k1.zwroc(0);
	std::cout << k1;
	k1.zwroc("zmyslony produkt");
	std::cout << k1;

	// copying constructor
	std::cout << "Testowanie konstruktora kopiujacego:\n";
	k1 + p1 + p2;
	Koszyk k2(k1);
	std::cout << k2;
	k1.zwroc(0);
	k1.zwroc(0);
	std::cout << k2; // gleboka kopia!

	// wybraneProdukty
	std::cout << "Testowanie metody wybraneProdukty(int, int)\n";
	Koszyk k3 = k2.wybraneProdukty(2, 3);
	std::cout << k3;

	return 0;
}
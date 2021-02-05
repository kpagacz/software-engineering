#include "Ksiazka.h"
#include "Czytelnik.h"
#include <iostream>

int main() {
	Podroze *k2 = new Podroze("ksiazka2");
	Fikcja * k3 = new Fikcja("ksiazka3");

	Czytelnik cz1;
	cz1 + k2 + k3;
	cz1.print(std::cout);
	cz1.zwroc("hello2");
	cz1.print(std::cout);

	std::cout << "Czytelnik cz2:\n";
	Czytelnik cz2(cz1);
	cz1.print(std::cout);
	
	std::cout << "Czytelnik cz3:\n";
	Czytelnik cz3 = cz2.wybraneKsiazki(Gatunki::Fikcja);
	cz3.print(std::cout);
	return 0;
}
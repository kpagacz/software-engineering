#include "Symbol.h"
#include "Plansza.h"

int main() {
	Plansza<Symbol> p(3, 3);
	p.print(std::cout);


	Kolko* k1 = new Kolko;
	Krzyzyk* k2 = new Krzyzyk;

	p.wstaw(0, 0, k1);
	p.print(std::cout);
	return 0;

	delete k1;
	delete k2;
}
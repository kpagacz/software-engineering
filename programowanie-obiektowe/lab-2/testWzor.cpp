// lab-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Wzor.h"
#include<vector>



int main()
{
	Wzor s1;
	Wzor s2('+', 4); //4 oznacza dlugosc wzoru, ’+’ oznacza znak z którego powstaje wzor,
	s1.opis();//wyœwietli komunikat: 3 x ’?’
	s1.drukuj(); //wyœwietli wzor: ???
	s2.opis();//wyœwietli komunikat: 4 x ’+’
	s2.drukuj(); //wyœwietli wzor: ++++
	s1.ustaw('*', 10);
	s1.opis();
	s1.drukuj();
	// Pod koniec dzia³ania programu wyœwietlaj¹ siê dwa komunikaty :
	//Obiekt (4,+) usuniêty
	//Obiekt (10,*) usuniety

	std::cout << "Podaj liczbe wzorow: ";
	unsigned int formulas_count;
	std::cin >> formulas_count;

	Wzor** formulas = new Wzor*[formulas_count];

	int _length;
	char _sign;
	for (int i = 0; i < formulas_count; i++) {
		std::cout << "Podaj znak oraz liczbe dodatnia: ";
		std::cin >> _sign >> _length;
		formulas[i] = new Wzor(_sign, _length);
		std::cout << "\n";
	}

	std::cout << "WZORY:\n";
	for (int i = 0; i < formulas_count; i++) {
		formulas[i]->drukuj();
	}
	for (int i = 0; i < formulas_count; i++) {
		delete formulas[i];
	}
	delete[] formulas;

	std::vector<Wzor*> patterns;
	char input = 'c';
	while (input == 'c') {
		std::cout << "Podaj znak oraz liczbe dodatnia: ";
		std::cin >> _sign >> _length;
		patterns.push_back(new Wzor(_sign, _length));
		std::cin >> input;
	}

	for (int i = 0; i < patterns.size(); i++) {
		patterns[i]->drukuj();
	}


	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

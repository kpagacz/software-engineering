#include <iostream>

#include "StackTP.h"

int main() {
	StackTP<int> stack;
	stack + 9 + 10 + 11;
	std::cout << stack;
	std::cout << "Removing the top element: ";
	std::cout << --stack << "\n";

	std::cout << "First element: " << stack[0] << "\n";
	std::cout << "Second element: " << stack[1] << "\n";

	// stack[5]; // returns an error

	stack.empty();
	std::cout << stack;


	StackTP<char> znaki; //tworzy pusty stos
	znaki + 's'; //dodaje element na stos;
	znaki + 'o';
	znaki + 'r';
	znaki + 's';
	znaki[1] = 't'; //zmienia drugi (od góry) element stosu
	std::cout << znaki; //wypisuje elementy stosu (nie usuwa stosu)
	std::cout << --znaki; //zdejmuje element ze stosu i go wypisuje
	znaki.empty(); //usuwa stos

	return 0;
}
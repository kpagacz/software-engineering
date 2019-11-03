#include <iostream>


int main () {
	// input
	std::cout << "Input an integer: ";
	int k;
	std::cin >> k;
	
	int divisor = 2;

	// calculations and output
	std::cout << "Factors of " << k << " are: ";

	while (k > 1) {
		if (k % divisor == 0) {
			std::cout << divisor << " ";
			k = k / divisor;
		} else {
			divisor++;
		}
	}
	return 0;
}

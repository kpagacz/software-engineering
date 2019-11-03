 

#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
	// input
	std::cout << "Input an integer: ";
	int k;
	std::cin >> k;

	// calculations
	// using Erasthotenes sieve
	bool *bool_table = new bool[k-2]; // false if not prime
	for (bool* ptr = bool_table; ptr <= bool_table + k - 1; ptr++) {
		*ptr = 1; // at the beginning all integers are presumed prime
	}
        
	int squared = sqrt(k); // a common optimization of the sieve - check numbers up to the square

	for (int i = 2; i <= squared; i++) {
		if (*(bool_table + i - 2) == 0) {
			continue; // already checked and not prime
		} else {
			// prime
			for (int j = i + 1; j <= k; j++) {
				// excluding multiples of the prime
				if (*(bool_table + j - 2) == true) {
					if (j % i == 0) {
						*(bool_table + j - 2) = false;
					}
				}
			}
		}
	}
	
	// output
	for (int i = 2; i <= k; i++) {
		if (*(bool_table + i - 2) == true) {
			std::cout << i << " ";
		}
	}
	return 0;
}

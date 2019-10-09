#include <iostream>

int main() {
	// input
	int length, time;
	std::cout << "Please, input the values of length and time" << std::endl;
	std::cin >> length;
	std::cin >> time;
	
	// calculations
	float velocity = length / (time / 60.0);
	
	// output
	std::cout << velocity;
	return 0;
}

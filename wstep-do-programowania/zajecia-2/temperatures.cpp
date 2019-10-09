#include <iostream>

int main() {
	// input
	float celsius, kelvin, fahrenheit;
	std::cout << "Please, input temperature in Celsius" << std::endl;
	std::cin >> celsius;
	
	// calculations
	kelvin = celsius + 273.15;
	fahrenheit = celsius * 1.8 + 32;
	
	// output
	std::cout << "Kelvin: " << kelvin << " Fahrenheit: " << fahrenheit;
	return 0;
}

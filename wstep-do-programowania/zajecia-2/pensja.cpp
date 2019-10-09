#include <iostream>
#include <iomanip>


int main() {
	// input
	float salary;
	std::cout << "Input the value of salary" << std::endl;
	std::cin >> salary;
	const int tax_rate = 19;
	
	// calculation
	float tax = tax_rate / 100.00 * salary;
	float netto = salary - tax;
	
	// output
	std::cout << std::setprecision(2) << std::fixed << "Netto: " << netto << " Tax amount: " << tax;
	
	return 0;
}

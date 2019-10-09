#include <iostream>
#include <iomanip>

int main() {
	// input
	float pln, euro, usd, chf;
	float pln_chf = 0.252, pln_euro = 0.231, pln_usd = 0.254;
	std::cout << "Please, input amount of money in PLN" << std::endl;
	std::cin >> pln;
	
	// calculations
	euro = pln * pln_euro;
	usd = pln * pln_usd;
	chf = pln * pln_chf;
	
	// output
	std::cout << std::setprecision(2) << std::fixed << "USD: " << usd << " EURO: " << euro << " CHF: " << chf;
	return 0;
}

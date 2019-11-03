#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
	// input
	float one_ton_price, apples_tons_start;
	int to_gain;
	const float odd_year_gain = 2.05, even_year_gain = 0.5;
	int years_needed = 1;

	std::cout << "Input price of one ton of aplles, starting number of tons of apples and money to be gained:" << std::endl;
	std::cin >> apples_tons_start >> one_ton_price >> to_gain;

	// input validation
	
	if (one_ton_price < 0 || apples_tons_start < 0 || to_gain < 0) {
		std::cout << "Invalid input. All number should be non-negative.";
	}
	

	if (one_ton_price == 0) {
		std::cout << "Not possible to achieve that gain in any number of years";
	}
	
	// calculations
	float total_gain = one_ton_price * apples_tons_start;
	float previous_gain = total_gain;

	while (total_gain < to_gain) {
		years_needed++;
		if (years_needed % 2 == 1) {
			total_gain = total_gain + previous_gain * odd_year_gain;
			previous_gain *= odd_year_gain;
		} else {
			total_gain = total_gain + previous_gain * even_year_gain;
			previous_gain *= even_year_gain;
		}	
	}
	
	// output
	std::cout << years_needed << " years is needed. Total gain: " << std::fixed << std::setprecision(2) << total_gain;
	return 0;
}

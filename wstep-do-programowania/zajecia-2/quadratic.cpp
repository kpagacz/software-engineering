#include <iostream>

int main() {
	// input
	int a, b, c;
	float x;
	std::cout << "Please input the coefficient a, b and c of the quadratic equation, as well as the value of the argument x" << std::endl;
	std::cin >> a >> b >> c >> x;
	
	// calculations
	float result = a * x*x + b * x + c;
	
	// output
	std::cout << result;
	
	return 0;
}

#include <iostream>
#include <iomanip>

double func(double x) {
	return x;
}

double BooleQuadrature(double a, double b, double f(double)) {
	double h = (b - a) / 4;

	return (b - a) / 90 * (7 * f(a) + 32 * f(a + h) + 12 * f(a + 2 * h) + 32 * f(a + 3 * h) + 7 * f(b));
}


int main() {
	std::cout << "Input a and b: ";
	double a, b;
	std::cin >> a >> b;

	std::cout << std::fixed << std::setprecision(4) << BooleQuadrature(a, b, func);

	return 0;
}
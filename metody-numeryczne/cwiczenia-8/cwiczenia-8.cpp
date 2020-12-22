#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <numeric>

double func(double x) {
	return exp(x);
}

double exact_integral(double x) {
	return exp(x);
}

double BooleQuadrature(double a, double b, double f(double)) {
	double h = (b - a) / 4;

	return (b - a) / 90 * (7 * f(a) + 32 * f(a + h) + 12 * f(a + 2 * h) + 32 * f(a + 3 * h) + 7 * f(b));
}

double TrapezoidQuadrature(double a, double b, double f(double)) {
	double h = (b - a) / 1;

	return (b - a) / 2 * (f(a) + f(b));
}

double ParaboleQuadrature(double a, double b, double f(double)) {
	double h = (b - a) / 2;

	return (b - a) / 6 * (f(a) + 4 * f(a + h) + f(b));
}

double ThreeEightsQuadrature(double a, double b, double f(double)) {
	double h = (b - a) / 3;
	return (b - a) / 8 * (f(a) + 3 * f(a + h) + 3 * f(a + 2 * h) + f(b));
}

void compoundNewtonCotes(double a, double b, double f(double), double F(double), double quadrature(double a, double b, double f(double)), int p) {
	double q = quadrature(a, b, f);
	int k = 1;

	std::cout << "Simple quadrature: " << q << "\n";
	
	do {
		long long N = pow(p, k);
		double H = (b - a) / N;
		q = 0;
		for (long long i = 0; i <= N - 1; i++)
			q += quadrature(a + i * H, a + (i + 1) * H, f);
		std::cout << "N: " << N << " q: " << q << " difference: " << std::setprecision(16) << abs(F(b) - F(a) - q) << "\n";
		k++;
	} while (k <= 25);

}

int main() {
	//std::cout << "Input a and b: ";
	//double a, b;
	//std::cin >> a >> b;

	/*std::cout << std::fixed << std::setprecision(16) << BooleQuadrature(a, b, func) << "\n";
	std::cout << std::fixed << std::setprecision(16) << "Exact value of integral: " << exact_integral(b) - exact_integral(a) << "\n";
	std::cout << std::fixed << std::setprecision(16) << "Difference: " << abs(exact_integral(b) - exact_integral(a) - BooleQuadrature(a, b, func)) << "\n";*/

	//for (int a = 0, b = 1; b <= 100; b *= 10) {
	//	std::cout << std::fixed << std::setprecision(16) << "Difference Boole: " << abs(exact_integral(b) - exact_integral(a) - BooleQuadrature(a, b, func)) << "\n";
	//	std::cout << std::fixed << std::setprecision(16) << "Difference Trapezoid: " << abs(exact_integral(b) - exact_integral(a) - TrapezoidQuadrature(a, b, func)) << "\n";
	//	std::cout << std::fixed << std::setprecision(16) << "Difference Parabole: " << abs(exact_integral(b) - exact_integral(a) - ParaboleQuadrature(a, b, func)) << "\n";
	//	std::cout << std::fixed << std::setprecision(16) << "Difference 3 / 8: " << abs(exact_integral(b) - exact_integral(a) - ThreeEightsQuadrature(a, b, func)) << "\n";
	//}

	//for (double a = 0, b = 1; b >= 0.001; b /= 10) {
	//	std::cout << std::fixed << std::setprecision(16) << "Difference Boole: " << abs(exact_integral(b) - exact_integral(a) - BooleQuadrature(a, b, func)) << "\n";
	//	std::cout << std::fixed << std::setprecision(16) << "Difference Trapezoid: " << abs(exact_integral(b) - exact_integral(a) - TrapezoidQuadrature(a, b, func)) << "\n";
	//	std::cout << std::fixed << std::setprecision(16) << "Difference Parabole: " << abs(exact_integral(b) - exact_integral(a) - ParaboleQuadrature(a, b, func)) << "\n";
	//	std::cout << std::fixed << std::setprecision(16) << "Difference 3 / 8: " << abs(exact_integral(b) - exact_integral(a) - ThreeEightsQuadrature(a, b, func)) << "\n";
	//}

	compoundNewtonCotes(0, 10, func, exact_integral, BooleQuadrature, 4);
	return 0;
}
#include<iostream>
#include<math.h>
#include<cmath>
#include<iomanip>


double f(double x);
double pierwiastek_bisekcja(double a, double b, double eps, double f(double));

int main() {

	std::cout << "Input a, b and epsilon: ";
	double a, b, eps;
	std::cin >> a >> b >> eps;
	
	double res = pierwiastek_bisekcja(a, b, eps, f);

	std::cout << "Estimation: " << std::setprecision(16) <<  res << "\n";
	return 0;
}


double f(double x) {
	return (x - 1.3) * pow(x + 1.7, 3);
}

double pierwiastek_bisekcja(double a, double b, double eps, double f(double)) {
	int counter = 0;
	double x;
	do
	{
		x = (a + b) / 2;
		if (std::signbit(f(a)) != std::signbit(f(x))) {
			b = x;
		}
		else {
			a = x;
		}
		counter++;
	} while (b - a > eps);

	std::cout << "Iterations: " << counter << "\n";
	return (a + b) / 2;
}
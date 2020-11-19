#include <stdlib.h>
#include <stdio.h>
#include<iostream>
#include <math.h>

using namespace std;

double f(double x)			// rozniczkowana funkcja
{
	return sin(x);
}

double fp(double x)			// SYMBOLICZNA PIERWSZA POCHODNA FUNKCJI
{                              		// POTRZEBNA JEDYNIE DO celow testowych
	return cos(x);
}

double form(double x, double h) 		// numeryczna formula rozniczkowania
{
	return (-f(x + 2 * h) + 8 * f(x + h) - 8 * f(x - h) + f(x - 2 * h)) / (12 * h);
}

double form2(double x, double h) {
	return (f(x) - f(x - h)) / h;
}

double form3(double x, double h) {
	return (-f(x + 2 * h) + 6 * f(x + h) - 3 * f(x) - 2 * f(x - h)) / (6 * h);
}

int main()
{
	double x0, d, d0, y, eps, h = 1.0;
	printf("Podaj punkt rozniczkowania x0=");
	cin >> x0;
	y = fp(x0);

	cout << "Rozniczkowanie bez kryterium stopu\n";
	printf("\n     h          przybl.poch       blad bezwzgledny     blad wzgledny\n");
	for (int i = 1; i <= 16; i++)
	{
		d = form(x0, h); // WYWOLANIE FORMULY
		printf("%.3e %.12e %.12e %.12e\n", h, d, fabs(y - d), fabs(y - d) / fabs(y));
		h /= 10;
	}

	cout << "Rozniczkowanie bez kryterium stopu\n";
	printf("\n     h          przybl.poch       blad bezwzgledny     blad wzgledny\n");
	h = 1.0;
	for (int i = 1; i <= 16; i++)
	{
		d = form2(x0, h); // WYWOLANIE FORMULY
		printf("%.3e %.12e %.12e %.12e\n", h, d, fabs(y - d), fabs(y - d) / fabs(y));
		h /= 10;
	}

	cout << "Rozniczkowanie bez kryterium stopu\n";
	printf("\n     h          przybl.poch       blad bezwzgledny     blad wzgledny\n");
	h = 1.0;
	for (int i = 1; i <= 16; i++)
	{
		d = form3(x0, h); // WYWOLANIE FORMULY
		printf("%.3e %.12e %.12e %.12e\n", h, d, fabs(y - d), fabs(y - d) / fabs(y));
		h /= 10;
	}


	return 0;
}
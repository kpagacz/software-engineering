// cwiczenia-6.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include<math.h>
#include <iomanip>

double custom_function(double x) {
    return (x - 1.3) * pow(x + 1.7, 3);
}

double differential(double x)
{
    return pow(10 * x + 17, 2) * (20 * x - 11) / 500;
}

double root_newton(double x, double eps) {
    int counter = 0;
    double h;
    do
    {
        h = -(custom_function(x) / differential(x));
        x += h;
        counter++;
    } while (abs(h) > eps);
    std::cout << "Iterations: " << counter << "\n";
    return x;
}


int main()
{
    double x_0 = -10;
    double h = 0.001;
    std::cout << std::fixed << std::setprecision(16) << root_newton(x_0, h);

    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

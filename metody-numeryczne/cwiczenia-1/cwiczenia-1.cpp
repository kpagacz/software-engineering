// cwiczenia-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <iomanip>


void problem1() {
    float f1 = 0.123456789, f2 = 0.123456788;
    float result1 = f1 - f2;
    std::cout << result1 << "\n";
    printf("%f\n", result1);

    double d1 = 0.123456789, d2 = 0.123456788;
    double result2 = d1 - d2;
    std::cout << std::setprecision(16) << result2 << "\n";
    printf("%f\n", result2);
}

int main()
{
    problem1();
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

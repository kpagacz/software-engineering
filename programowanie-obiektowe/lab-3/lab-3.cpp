// lab-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Fraction.h"

int main()
{
    Fraction f1(1, 2);
    Fraction f2(2, 3);
    std::cout << f1;

    // addition
    Fraction f3 = f1 + f2;
    std::cout << f3;

    // subtraction
    Fraction f4 = f2 - f1;
    std::cout << f4;

    // inversing fraction
    Fraction f5 = -f1;
    std::cout << f5;

    // reverse fraction
    Fraction f6 = !f1;
    std::cout << f6;

    // multiplication
    Fraction f7 = f1 * 3;
    std::cout << f7;

    std::cout << 3 * f1;

    // division
    std::cout << f1 / 2;
    std::cout << 2 / f1;

    // simplification
    Fraction f8(4, 8);
    f8.simplify();
    std::cout << f8;

    // cin
    Fraction f9(1, 1);
    std::cin >> f9;
    std::cout << f9;

    // double conversion
    std::cout << double(f1);
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

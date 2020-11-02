// cwiczenia-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include <iomanip>

template <class T>
void problem_c(int k) {
    T first_expr = (sqrt(pow(3, -1 * k) * pow(3, -1 * k) + 1) - 1);
    T second_expr = (pow(3, -1 * k) * pow(3, -1 * k)) / (sqrt(pow(3, -1 * k) * pow(3, -1 * k) + 1) + 1);

    std::cout << std::fixed << std::setprecision(16) << "First: " << first_expr << "\nSecond: " << second_expr << "\n";
}

template<>
void problem_c<float>(int k) {
    float first_expr = (sqrtf(powf(3, -1 * k) * powf(3, -1 * k) + 1) - 1);
    float second_expr = (powf(3, -1 * k) * powf(3, -1 * k)) / (sqrtf(powf(3, -1 * k) * powf(3, -1 * k) + 1) + 1);

    std::cout << std::fixed << std::setprecision(8) << "First: " << first_expr << "\nSecond: " << second_expr << "\n";
}

int main()
{
    for (int i = 1; i < 25; i++) {
        std::cout << "k = " << i << "\n";
        std::cout << "Doubles\n";
        problem_c<double>(i);
        std::cout << "Floats\n";
        problem_c<float>(i);
        std::cout << "==================\n";
    }
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

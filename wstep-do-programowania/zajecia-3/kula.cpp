#define _USE_MATH_DEFINES
#undef __STRICT_ANSI__
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    // input
    int radius;
    std::cout << "Provide integer of the radius. \n";
    std::cin >> radius;

    char choice;
    std::cout << "Provide the desired output: area (a) or volume(v).\n";
    std::cin >> choice;

    // calculations
    if (choice == 'a') {
        std::cout << std::fixed << std::setprecision(2) <<  "Area is: " << 4 * M_PI * pow(1.0 * radius, 2);
    } else {
        if (choice == 'v') {
            std::cout << std::fixed << std::setprecision(2) << "Volume is: " << 4.0 / 3 * M_PI * pow(1.0 * radius, 3);
        } else {
            std::cout << "Please choose area (a) or volume(v).";
        }
    }
    return 0;
}
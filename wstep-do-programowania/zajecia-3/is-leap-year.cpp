#include <iostream>


int main() {
    // input
    int year;
    std::cout << "Please provide a year. ";
    std::cin >> year;

    // calculations
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        std::cout << "It's a leap year!";
    } else {
        std::cout << "It is not a leap year :(.";
    }
    return 0;
}
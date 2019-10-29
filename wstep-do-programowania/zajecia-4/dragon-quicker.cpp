#include <iostream>

int main() {
    // input
    std::cout << "Please input the number of days the dragon rampaged the kingdom.\n";
    int days;
    std::cin >> days;

    // calculations
    int eaten_today = (days * (days - 1)) / 2 + 1;

    std::cout << "Sheep eaten today: " << eaten_today << " . Total sheep eaten: ";
    return 0;
}
#include <iostream>

int main() {
    // input
    std::cout << "Please input the number of days the dragon rampaged the kingdom.\n";
    int days;
    std::cin >> days;

    // calculations
    int total_sheep_eaten = 3;
    int eaten_today = 2;
    int eaten_yesterday = 1;

    if (days == 1) {
        std::cout << "Today eaten: 1. Sum: 1";
        return 0; 
    }

    if (days == 2) {
        std::cout << "Today eaten: 2. Sum: 3";
        return 0;
    }

    for (int i = 3; i <= days; i++) {
        int yest = eaten_today;
        eaten_today = 2 * eaten_today - eaten_yesterday + 1;
        eaten_yesterday = yest;
        total_sheep_eaten += eaten_today;
    }

    std::cout << "Sheep eaten today: " << eaten_today << " . Total sheep eaten: " << total_sheep_eaten;
    return 0;
}
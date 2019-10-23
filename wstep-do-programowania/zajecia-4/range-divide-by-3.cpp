#include <iostream>
#include <cmath>

int main() {
    // input
    int a, b;
    std::cout << "Please input two integers.\n";
    std::cin >> a >> b;

    int sum = 0;
    int number_of_divisiable_by_three = 0;

    int lower = (a < b)? a : b;
    int higher = (a > b)? a : b;

    int divisable[100000];

    // calculations
    for (int i = higher; i >= lower; i--) {
        if (i % 3 == 0) {
            sum += i;
            divisable[number_of_divisiable_by_three] = i;
            number_of_divisiable_by_three++;
            //std::cout << i << " ";
        }
    }

    // output
    std::cout << "Between numbers " << lower << " and " << higher << " are " << number_of_divisiable_by_three << " instances of numbers divisable by 3." << std::endl;
    std::cout << "The sum of those numbers is: " << sum << std::endl;
    std::cout << "Those numbers are: ";
    for (int i = 0; i < number_of_divisiable_by_three; i ++ ) {
        std::cout << divisable[i] << " ";
    }
    return 0;
}
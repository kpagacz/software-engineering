#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    // input
    std::cout << "Please input a single integer. ";
    int a;
    std::cin >> a;
    float result;

    // calculations
    if (a % 2 == 0) {
        result = pow(a, 3);
    } else {
        result = pow(a, 1.0 / 3);
    }
    std::cout << "Result is: " << result;
    return 0;
}
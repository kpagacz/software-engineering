#include <iostream>

int main() {
    // input
    std::cout << "Provide two integers\n";
    float a, b;
    std::cin >> a >> b;

    // calculations
    if (a == 0) {
        if (b == 0) {
            std::cout << "Infinite number of solutions";
        } else {
            std::cout << "No solutions in real numbers";
        }
    } else {
        std::cout << "Solution is: " << -b / a; 
    }
    return 0;
}
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    // input
    int a, b, c;
    std::cout << "Please provide coefficients a, b, c of a quadratic equation ax^2 + bx + c = 0.\n";
    std::cin >> a >> b >> c;

    // calculations
    if (a == 0) {
        std::cout << "Coefficient a cannot be 0, otherwise the equation is not quadratic. Provide valid coefficients.";
    } else {
        float delta = b*b - 4*a*c;
        if (delta < 0) {
            std::cout << "There is no real solutions.";
        } else {
            if (delta == 0) {
                std::cout << std::fixed << std::setprecision(2) << "There is only one solution: " << -b / 2.0 / a;
            } else {
                std::cout << std::fixed << std::setprecision(2) << "Solutions are: " << (-b - sqrt(delta)) / 2.0 / a << " and " << (-b + sqrt(delta)) / 2.0 / a;
            }
        }
    }
   return 0;
}
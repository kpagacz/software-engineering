#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    // input
    int a, b, c;
    std::cout << "Please, input 3 integers - sides of a triangle.\n";
    std::cin >> a >> b >> c;

    // calculations and output
    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        float p = (a + b + c) / 2.0;
        float area = sqrt(p * (p - a) * (p - b) * (p - c));
        std::cout << std::fixed << std::setprecision(2) << "Area is: " << area ;
    } else {
        std::cout << "Please provide valid sides of a triangle.";
    }
    return 0;
}
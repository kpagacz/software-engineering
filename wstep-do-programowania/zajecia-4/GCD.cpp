#include <iostream>

int main() {
    // input 
    std::cout << "Please provide two integers.\n";
    int a1, b1;
    int previous;
    std::cin >> a1 >> b1;

    std::cout << "GCD of " << a1 << " and " << b1 << " is: ";

    int a, b;
    if (a1 > b1) {
        a = a1;
        b = b1;
    } else {
        a = b1;
        b = a1;
    }

    // calculations
    
    while (b != 0) {
        previous = a;
        a = b;
        b = previous % b;
    }

    // output
    std::cout << a;
    return 0;
}
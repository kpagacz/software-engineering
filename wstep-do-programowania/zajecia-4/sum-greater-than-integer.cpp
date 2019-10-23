#include <iostream>
#include <cmath>

int main() {
    // input 
    std::cout << "Please provide a positive integer.\n";
    int G;

    do {
        std::cin >> G;
    } while (G < 1);

    // calculations
    // int smallest = ceil((-1 + sqrt(1 + 8 * G)) / 2.0);


    int suma = 0;
    int smallest = 0;

    while (suma < G) {
        smallest ++;
        suma += smallest;
    }

    // output
    std::cout << "The smallest number of integers to add is: " << smallest << std::endl;
    return 0;
}
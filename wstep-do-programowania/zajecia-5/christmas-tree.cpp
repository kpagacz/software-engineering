// Napisać program, który "rysuje" choinkę o liczbie 
// segmentów podanej przez użytkownika. 
// Przykładowo dla dwóch segmentów powinno się uzyskać
//   *
//  ***
//   *
//  ***
// *****
#include <iostream>
#include <iomanip>

int main() {
    // input
    std::cout << "Input number of segments: ";
    int segments;
    std::cin >> segments;

    // outputting
    for (int i = 1; i <= segments; i++) {
        // segment loop
        for (int j = 1; j <= i + 1; j++) {
            // line loop
            std::cout << std::setw(segments + 1 - (j - 1)) << "*";
            for (int k = 1; k <= 2 * j - 2; k++) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }
}
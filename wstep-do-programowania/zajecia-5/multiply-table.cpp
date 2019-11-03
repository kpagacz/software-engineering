#include <iostream>
#include <iomanip>

int main() {
    // input
    std::cout << "Inpul a natural number:";
    int G;
    std::cin >> G;

    // output
    const int width = 5;

    // first line
    for (int i = 0; i < width; i++) {
        std::cout << " ";
    }

    for (int i = 1; i <= G; i++) {
        std::cout << std::setw(width) << i;
    }

    std::cout << std::endl;

    // next lines
    for (int j = 1; j <= G; j++) {
        std::cout << std::setw(width) << j;
        for (int i = 1; i <= G; i++) {
            std::cout << std::setw(width) << i * j;
        }
        std::cout << std::endl;
    }
    return 0;
}
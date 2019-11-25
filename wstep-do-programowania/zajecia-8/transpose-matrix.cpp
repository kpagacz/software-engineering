// Napisać program, który pobierze kwadratową tablicę liczb 
// całkowitych i wypisze jej kolejne kolumny jako wiersze.
// Przykład: dla tablicy

// 1 2 3
// 4 5 6
// 7 8 9

// program powinien wypisać tablicę:

// 1 4 7
// 2 5 8
// 3 6 9

#include <iostream>
#include <iomanip>

int main() {
    // config
    const int n_width = 3;
    // input
    int size;
    std::cout << "Input size of the matrix: ";
    std::cin >> size;

    int* matrix = new int[size * size];

    std::cout << "Input the matrix:" << std::endl;
    for (int i = 0; i < size * size; i++) {
        std::cin >> matrix[i];
    }

    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size; j ++) {
            std::cout << std::setw(n_width) << matrix[j * size + i] << " ";
        }
        std::cout << std::endl;
    }

    delete [] matrix;
    return 0;
}
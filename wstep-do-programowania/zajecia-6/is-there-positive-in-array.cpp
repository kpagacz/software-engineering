// Napisać program, który pobiera od użytkownika tablicę liczb całkowitych 
// o podanej przez użytkownika długości, a następnie wypisuje 
// informację czy w tablicy jest liczba dodatnia. 

#include <iostream>

int main() {
    // input
    int length;
    std::cout << "Input length of the array: ";
    std::cin >> length;
    std::cout << std::endl;

    int* array = new int[length];
    bool positive = false;

    for (int i = 0; i < length; i++) {
        std::cout << "Input a number: ";
        std::cin >> array[i];
        if (array[i] > 0) {
            positive = true;
        }
    }

    // output number of pairs
    if (positive) {
        std::cout << "There is a positive number in the array." << std::endl;
    }

    delete [] array;

    return 0;
}
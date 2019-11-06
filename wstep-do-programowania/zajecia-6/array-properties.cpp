// Napisać program, który wczytuje tablicę wartości rzeczywistych o długości podanej przez użytkownika, a następnie wypisuje informacje:

//     czy te liczby są uporządkowane rosnąco lub malejąco,
//     czy tablica jest symetryczna (pierwszy element równy ostatniemu, drugi przedostatniemu itd),
//     czy w tablicy występuje przynajmniej jedno powtórzenie wartości.

#include <iostream>


int main() {
    // input array length
    int array_length;
    std::cout << "Input array length: ";
    std::cin >> array_length;

    // initialize array
    int* array = new int[array_length];

    // input elements
    std::cout << "Input elements: ";
    for (int i = 0; i < array_length; i ++) {
        std::cin >> array[i];
    }

    // is monotonically increasing
    bool increasing = true;

    for (int i = 0; i < array_length - 1; i++) {
        if (array[i + 1] <= array[i]) {
            increasing = false;
            break;
        }
    }

    if (increasing) {
        std::cout << "Sequence is monotonically increasing." << std::endl;
    } else {
        std::cout << "Sequence is not monotoniclly increasing." << std::endl;
    }


    // is monotonically decreasing
    bool decreasing = true;

    for (int i = 0; i < array_length - 1; i++) {
        if (array[i + 1] >= array[i]) {
            decreasing = false;
            break;
        }
    }

    if (decreasing) {
        std::cout << "Sequence is monotonically decreasing." << std::endl;
    } else {
        std::cout << "Sequence is not monotoniclly decreasing." << std::endl;
    }

    // is array palindromic
    bool palindromic = true;

    for (int i = 0; i < array_length / 2; i++) {
        if (array[i] != array[array_length - 1 - i]) {
            palindromic = false;
            break;
        }
    }

    if (palindromic) {
        std::cout << "Sequence is palindromic." << std::endl;
    } else {
        std::cout << "Sequence is not palindromic." << std::endl;
    }

    // is there at least one duplicate element
    bool duplicate = false;

    for (int i = 0; i < array_length - 1; i++) {
        for (int j = i + 1; j < array_length; j++) {
            if (array[i] == array[j]) {
                duplicate = true;
                break;
            }
        }
        if (duplicate) {
            break;
        }
    }

    if (duplicate) {
        std::cout << "There is at least one duplicate element." << std::endl;
    } else {
        std::cout << "There are no duplicate elements." << std::endl;
    }

    delete [] array;
    return 0;
}
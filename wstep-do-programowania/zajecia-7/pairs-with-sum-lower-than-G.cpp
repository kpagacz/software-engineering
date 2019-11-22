// Napisać program wczytujący tablicę liczb całkowitych o podanej przez użytkownika długości, 
// a następnie wypisujący wszystkie takie dwójki (pary nieuporządkowane) utworzone z elementów 
// tej tablicy, że ich suma jest mniejsza od podanej przez użytkownika liczby G. 

#include <iostream>

int main() {
    std::cout << "Input array length: ";
    int length;
    std::cin >> length;

    int* tab = new int[length];

    std::cout << "Input number G: ";
    int G;
    std::cin >> G;

    std::cout << "Input elements of the array: ";
    for (int i = 0; i < length; i++) {
        std::cin >> tab[i];
    }


    std::cout << "Unordered pairs, which sum to lower than G are:" << std::endl;

    // iterating through all pairs
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if(tab[i] + tab[j] < G) {
                std::cout << tab[i] << " " << tab[j] << std::endl;
            }
        }
    }

    delete [] tab;
    return 0;
}
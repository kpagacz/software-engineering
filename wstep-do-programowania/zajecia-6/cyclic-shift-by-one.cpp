// Napisać program, który pobiera liczby do tablicy 
// o długości podanej przez użytkownika, a następnie
// dokonuje przesunięcia zawartości tej tablicy 
// cyklicznie o jedną pozycję (pierwszy element na 
// miejsce drugiego, drugi na miejsce trzeciego, ...,
// ostatni na miejsce pierwszego). 

#include <iostream>

int main() {
    // input array length
    int array_length;
    std::cout << "Input array length: ";
    std::cin >> array_length;

    // array initialization
    int* array = new int[array_length];
    
    std::cout << "Input elements: ";
    // read array elements
    for (int i = 0; i < array_length; i++) {
        std::cin >> array[i];
    }


    // output the shifted array
    for (int i = array_length - 1; i <= 2 * array_length - 2; i++) {
        std::cout << array[(i) % array_length] << " ";
    }


    delete [] array;
    return 0;   
}
// Napisać program pobierający tablicę liczb całkowitych o 
// podanej przez użytkownika długości, a następnie 
// wypisujący liczbę wystąpień poszczególnych wartości tej tablicy. 

#include <iostream>

int main() {
    // input
    std::cout << "Input array length: ";
    int array_length;
    std::cin >> array_length;

    std::cout << "Input array elements: ";
    int* array = new int[array_length];

    for (int i = 0; i < array_length; i++) {
        std::cin >> array[i];
    }

    // counting occurances for each element of the table

    for (int i = 0; i < array_length; i++) {
        int occurances = 1;
        
        for (int j = 0; j < array_length; j++) {
            if (i != j and array[i] == array[j]) {
                occurances++;
            }
        }

        std::cout << i + 1 << ". element of the array - " << array[i] << " - occured " << occurances << " times in the array." << std::endl;
    
    }

    delete [] array;
    return 0;
}



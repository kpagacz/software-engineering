// Napisać program zawierający następujące funkcje:

//     funkcję pobierającą (z klawiatury) zawartość tablicy liczb całkowitych podanej jako parametr, o długości podanej jako parametr;
//     funkcję wypisującą zawartość tablicy liczb całkowitych podanej jako parametr o długości podanej jako parametr;
//     funkcję wypełniającą tablicę liczb całkowitych podaną jako parametr wartościami losowymi z zakresu podanego jako parametr
//     funkcję TablicaMniejszych o (przynajmniej) dwóch parametrach: jednym będącym tablicą liczb całkowitych, drugim będącym liczbą całkowitą 
//          (jeśli potrzebne są również inne parametry, należy je dodać). Funkcja ma zwracać tablicę utworzoną na podstawie tablicy 
//          podanej jako parametr poprzez usunięcie wszystkich elementów nie mniejszych niż liczba podana jako drugi parametr.
//     funkcję NajdluzszyCiagArytmetyczny zwracającą tablicę liczb całkowitych powstałą z tablicy liczb całkowitych podanej 
//          jako parametr poprzez przekopiowanie do tablicy wynikowej najdłuższej podtablicy (tj. ciągu sąsiednich elementów tej tablicy) 
//          zawierającej ciąg arytmetyczny, czyli taki, że dla każdego jego elementu (poza pierwszym) różnica tego elementu i 
//          elementu bezpośrednio go poprzedzającego w tym ciągu jest taka sama (np. dla tablicy 1,7,-2,4,10,1,11,8,5,2,8,9, 
//          zwrócony ma być fragment 11,8,5,2, natomiast dla tablicy 3,2,4,1 zwrócona ma być dowolna para sąsiednich elementów). 
//          W przypadku gdy tablica wejściowa zawiera kilka podtablic spełniającyych podany warunek i mających długość taką jak 
//          najdłuższa, zwrócona ma być jedna z nich. 

// oraz program tworzący tablicę liczb całkowitych o długości podanej przez użytkownika i testujący powyższe funkcje. 

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstring>


void inputArray(int* array, int& length);
void outputArray(int* array, int& length);
void randomArray(int* array, int& lower_bound, int& upper_bound, int& length);
int* TablicaMniejszych(int* array, int& threshold, int& length, int& smaller);
int* NajdluzszyCiagArytmetyczny(int* array, int& length, int& arithmetic_length);
int* longestArithmeticSeq(int* array, int& length, int& arithmetic_length);

int main() {
    // input
    std::cout << "Input length of the array: ";
    int length;
    std::cin >> length;

    int* array = new int[length];

    inputArray(array, length);

    // output user array
    std::cout << "User defined array is: ";
    outputArray(array, length);

    // random array
    std::cout << "Input lower and upper bound for randomizing array elements: ";
    int lower, upper;
    std::cin >> lower >> upper;

    randomArray(array, lower, upper, length);

    // output random array
    std::cout << "Randomized array is: ";
    outputArray(array, length);

    // cutting out values smaller than x
    std::cout << "Input threshold: ";
    int threshold;
    std::cin >> threshold;

    int smaller_length;

    int* smaller_array = TablicaMniejszych(array, threshold, length, smaller_length);

    // outputting smaller
    std::cout << "Array after cutting out not smaller than threshold:" << std::endl;
    outputArray(smaller_array, smaller_length);

    // input array from user
    inputArray(array, length);
    // find longest arithmetic sequence
    int arithmetic_length;

    int* longest_arithmetic = longestArithmeticSeq(array, length, arithmetic_length);

    // output longest arithmetic sequence
    std::cout << "Longest arithmetic sequence:" << std::endl;
    outputArray(longest_arithmetic, arithmetic_length);

    delete [] array, longest_arithmetic;
    delete [] smaller_array;
    return 0;
}


void inputArray(int* array, int& length) {
    std::cout << "Input array elements:" << std::endl;
    for (int i = 0; i < length; i++) {
        std::cin >> array[i];
    }
}

void outputArray(int* array, int& length) {
    for (int i = 0; i < length; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void randomArray(int* array, int& lower_bound, int& upper_bound, int& length) {
    std::cout << "Randomizing array elements.";
    // randomize seed
    srand(time(NULL));

    int random;

    for (int i = 0; i < length; i++) {
        random = rand()%(upper_bound + 1 - lower_bound) + lower_bound;
        array[i] = random;
    }
}

int* TablicaMniejszych(int* array, int& threshold, int& length, int& smaller) {
    // counting smaller numbers
    smaller = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] < threshold) {
            smaller++;
        }
    }

    int* smaller_array = new int[smaller];
    
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] < threshold) {
            smaller_array[j] = array[i];
            j++;
        }
    }
    
    return smaller_array;
}
int* NajdluzszyCiagArytmetyczny(int* array, int& length, int& arithmetic_length) {
    int lower_ind = 0;
    int upper_ind = 1;
    arithmetic_length = 0;
    int max_lower_ind = 0;

    int current_ind = 1;
    int past_difference = array[1] - array[0];
    int current_difference;

    while(current_ind < length) {
        // calculate current difference
        current_difference = array[current_ind] - array[current_ind - 1];

        while (current_difference == past_difference && current_ind < length) {
            // if is the same as before, increase upper ind by one
            current_ind++;
            current_difference = array[current_ind] - array[current_ind - 1];
        } 
        
        // if is different, check whether the length is larger than the current max
        if (current_ind - lower_ind > arithmetic_length) {
            max_lower_ind = lower_ind;
            arithmetic_length = current_ind - lower_ind;
        }
        // and reset the values
        lower_ind = current_ind - 1;
        past_difference = current_difference;
        current_ind++;
    }

    int* arithm = new int[arithmetic_length];

    for (int i = 0; i <  arithmetic_length; i++) {
        arithm[i] = array[max_lower_ind + i];
    }

    return arithm;
}

int* longestArithmeticSeq(int* array, int& length, int& arithmetic_length) {
    int max_lower_ind = 0;
    int lower_ind = 0;
    arithmetic_length = 0;

    int past_difference = array[1] - array[0];
    int current_difference;

    for (int i = 1; i < length; i ++) {
        current_difference = array[i] - array[i - 1];
        if (current_difference == past_difference) {
            if (i - lower_ind + 1 > arithmetic_length) {
                arithmetic_length = i - lower_ind + 1;
                max_lower_ind = lower_ind;
            }
        } else { 
            past_difference = current_difference;
            lower_ind = i - 1;
        }
    }

    int* arithm = new int[arithmetic_length];
    for (int i = 0; i < arithmetic_length; i++) {
        arithm[i] = array[max_lower_ind + i];
    }
    return arithm;
}

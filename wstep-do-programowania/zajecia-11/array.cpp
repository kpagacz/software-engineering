// Napisać program zawierający następujące funkcje:
// - funkcję pobierającą (z klawiatury) zawartość tablicy liczb całkowitych podanej jako parametr, o długości podanej jako parametr;
// - funkcję wypisującą zawartość tablicy podanej jako parametr o długości podanej jako parametr;
// - funkcję modyfikującą tablicę liczb całkowitych podaną jako parametr przez zastąpienie w niej wszystkich liczb nieparzystych zerami
// - funkcję zwracającą wartość logiczną mówiącą, czy tablica podana jako parametr o długości podanej jako parametr jest uporządkowana rosnąco,
// - funkcję zwracającą wartość logiczną mówiącą, czy tablica podana jako parametr o długości podanej jako parametr 
//      jest symetryczna (pierwszy element jest równy ostatniemu, drugi - przedostatniemu itd),
// - funkcję zwracającą wartość logiczną mówiącą, czy tablica podana jako parametr o długości podanej jako parametr zawiera powtórzenia.
// - funkcję modyfikującą zawartość tablicy podanej jako parametr poprzez zastąpienie średnią elementów tablicy (zaokrągloną do liczby całkowitej) 
//      wszystkich elementów mniejszych od tej średniej.
// Napisać program tworzący tablicę liczb całkowitych o podanej przez użytkownika długości, 
// a następnie wykorzystujący powyższe funkcje do wypełnienia i wypisania tablicy oraz sprawdzenia 
// czy zawiera ona powtórzenia, czy jest uporządkowana rosnąco i czy jest symetryczna, 
// oraz zastąpienia średnią elementów mniejszych od średniej i ponownego wypisania tablicy, 
// a następnie zastąpienia liczb nieparzystych zerami i kolejnego wypisania tablicy.

#include <iostream>
#include <cmath>

void input_values(int* array, const int& length);
void print_array(int* array, const int& length);
void replace_odd(int* array, const int& length);
bool is_increasing(int* array, const int& length);
bool is_palindrome(int* array, const int& length);
bool are_repeats(int* array, const int& length);
void replace_with_mean(int* array, const int& length);

int main() {
    int length;
    std::cout << "Input array length: ";
    std::cin >> length;

    int* array = new int[length];

    input_values(array, length);

    print_array(array, length);

    if (are_repeats(array, length)) {
        std::cout << "Array contains repeats." << std::endl;
    } else {
        std::cout << "Array does not contain repeats." << std::endl;
    }

    if (is_increasing(array, length)) {
        std::cout << "Array is monotonically increasing." << std::endl;
    } else {
        std::cout << "Array is not monotonically increasing." << std::endl;
    }

    if (is_palindrome(array, length)) {
        std::cout << "Array is palindromic." << std::endl;
    } else {
        std::cout << "Array is not palindromic." << std::endl;
    }

    replace_with_mean(array, length);
    print_array(array, length);

    replace_odd(array, length);
    print_array(array, length);

    delete [] array;
    return 0;
}


void input_values (int* array, const int& length) {
    std::cout << "Input array elements: ";
    for (int i = 0; i < length; i++) {
        std::cin >> array[i];
    }
}

void print_array(int* array, const int& length) {
    for (int i = 0; i < length; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void replace_odd(int* array, const int& length) {
    for (int i = 0; i < length; i++) {
        if (array[i] % 2 == 1) {
            array[i] = 0;
        }
    }
}

bool is_increasing(int* array, const int& length) {
    bool increasing = true;
    for (int i = 0; i < length - 1; i++) {
        if (array[i + 1] < array[i]) {
            increasing = false;
            break;
        }
    }
    return increasing;
}

bool is_palindrome(int* array, const int& length) {
    bool palindrome = true;
    for (int i = 0; i < length / 2; i++) {
        if (array[i] != array[length - i - 1]) {
            palindrome = false;
            break;
        }
    }
    return palindrome;
}

bool are_repeats(int* array, const int& length) {
    bool repeats = false;
    for (int i = 0; i < length - 1; i++) {
        for (int j = i; j < length; j++) {
            if (array[i] == array[j]) {
                repeats = true;
                break;
            }
        }
    }
    return repeats;
}

void replace_with_mean(int* array, const int& length) {
    float mean = 0;
    for (int i = 0; i < length; i ++) {
        mean += array[i];
    }

    mean = round(mean / length);

    for (int i = 0; i < length; i++) {
        if (array[i] < mean) {
            array[i] = mean;
        }
    }
}
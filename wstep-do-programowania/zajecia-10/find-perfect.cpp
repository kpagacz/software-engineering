// Napisać funkcję sprawdzającą czy liczba jest doskonała, 
// tzn. jest sumą swoich dzielników właściwych (tj. 
// mniejszych od niej, np. 6=1+2+3 jest doskonała). 
// Napisać program znajdujący cztery najmniejsze liczby doskonałe. 

#include <iostream>

bool isPerfect(int a);

int main() {
    std::cout << "Finding the 4 lowest perfect numbers" << std::endl;

    int perfect_found = 0;
    const int end = 4;
    int current_number = 2;

    while (perfect_found < end) {
        if (isPerfect(current_number)) {
            std::cout << "Found perfect number: " << current_number << std::endl;
            perfect_found ++;
        }
        current_number ++;
    }
    return 0;
}


bool isPerfect(int a) {
    int sum = 0;

    for (int i = 1; i < a; i++) {
        if (a % i == 0) {
            sum += i;
        }
    }

    return sum == a;
}

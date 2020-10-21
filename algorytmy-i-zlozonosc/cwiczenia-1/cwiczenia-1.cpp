// cwiczenia-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>

void print_stars() {
    for (int i = 5; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

void szachownica() {
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 4; k++) {
            for (int j = 0; j < 4; j++) {
                if (i % 2 == 0) {
                    std::cout << "*";
                }
                else {
                    std::cout << " ";
                }
            }

            for (int j = 0; j < 4; j++) {
                if (i % 2 == 0) {
                    std::cout << " ";
                }
                else {
                    std::cout << "*";
                }
            }

            for (int j = 0; j < 4; j++) {
                if (i % 2 == 0) {
                    std::cout << "*";
                }
                else {
                    std::cout << " ";
                }
            }
            std::cout << "\n";
        }
    }
}

void szachownica2() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (!((i / 4 + j / 4) % 2)) {
                std::cout << "*";
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}

bool isPrime(int number) {
    bool is_prime = true;
    for (int i = 2; i <= sqrt(number); i++) {
        is_prime = !(number % i == 0);
        if (!is_prime) {
            break;
        }
    }

    return is_prime;
}

void erastothenes_primes() {
    bool tab[5000] = {};

    for (int i = 2; i < 5000; i++) { 
        if (tab[i] == 0) {
            std::cout << i << " ";
            for (int j = i * i; j < 5000; j += i) { // mozna zaczac od i^2!!
                tab[j] = 1;
            }
        }
    }
}


// mozna tylko korzystac z ==
// czy jest element wiekszosciowy
bool isMajorityElement(int tab[], int length) {


    for (int i = 0; i < length; i++) {
        int sum = 0;
        for (int j = 0; j < length; j++) {
            if (tab[i] == tab[j]) {
                sum++;
            }
        }

        if (sum > length / 2) {
            return true;
        }
    }

    return false;
}

// beda dwa passy
// I. pierwszy element 
// dwie zmienne: jaki aktualnie jest kandydat oraz licznik
// pierwszy element - kandydat
// licznik = 1
// 
//
//
// Moore's voting algorithm
bool isMajorityElementBetter(int tab[], int length) {
    int candidate, counter = 0;

    for (int i = 0; i < length; i++) {
        if (counter == 0) {
            candidate = tab[i];
            counter = 1;
        }
        else {
            if (tab[i] == candidate) {
                counter++;
            }
            else {
                counter--;
            }
        }
    }

    int total_counter = 0;
    for (int i = 0; i < length; i++) {
        if (tab[i] == candidate) {
            total_counter++;
        }

        if (total_counter > length / 2) {
            return true;
        }
    }

    return false;
}

int main()
{
    std::cout << "Hello World!\n";

    /*print_stars();
    szachownica();
    szachownica2();
    std::cout << isPrime(2) << "\n";
    erastothenes_primes();*/

    int arr[5] = { 1, 2, 3, 4, 5 };
    int arr2[5] = { 1,1,1, 2, 3 };

    std::cout << isMajorityElement(arr, 5) << std::endl;
    std::cout << isMajorityElement(arr2, 5) << std::endl;

    std::cout << isMajorityElementBetter(arr, 5) << std::endl;
    std::cout << isMajorityElementBetter(arr2, 5) << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

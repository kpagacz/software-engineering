//  Napisać   program,   który   wczytuje   dodatnie   liczby  
//  całkowite   aż   do   napotkania   liczby   0   
//  (w przypadku   wprowadzenia   z   klawiatury   liczby   ujemnej  
//   należy   wymusić   wprowadzenie dopuszczalnej wartości) i wypisuje 
//   na ekranie wszystkie te czwórki kolejno wczytanych liczb które
//   zawierają co najwyżej 2 liczby podzielne przez wartość K, będącą liczbą całkowitą dodatnią podaną
//   przez   użytkownika     (końcowe   zero   nie   jest   brane   pod   uwagę).   W   przypadku   nie
//   znalezienia odpowiedniej czwórki należy wyprowadzić stosowny komunikat. 
//   Przykład: Jeśli K=3 i kolejno wprowadzane liczby to: 
//   3,1,3,6,5,9,4,3,1,2,0, 
//   to należy wypisać następujące czwórki: 
//   (1,3,6,5), (6,5,9,4), (5,9,4,3), (9,4,3,1), (4,3,1,2). 
//   Jeśli natomiast dla K=2 wczytywane liczby
//   składają się na ciąg: 2,1,4,2,6,3,8,0 
//   to powinien pojawić się komunikat: „Brak szukanych czwórek liczb”.

#include <iostream>

/* Possible optimizations:
- shift the number, while looking for divisible (marked *)
- count the divisble only once and then track if the last forgotten number
was divisible and if the last inputted number is divisible, adding and substracting
from divisible as needed - would need to left out the shit loop intact

However I cut it, one loop in my current implementation is unnecessary.
*/ 

int main() {
    // input K
    int K;
    do {
        std::cout << "Input positive integer K: ";
        std::cin >> K;
    } while (K < 0);

    // number_of_fours trakcs the number of 4-element subsequences, which fulfill the requirments from the excercise
    int number_of_fours = 0;

    // first 4 numbers; array will contain last 4 inputted elements in each iteration of the loop
    int array[4] = {0};

    // single_number is recently inputted number
    int single_number;

    // inputting first 4 numbers
    for (int i = 0; i < 4; i++) {
        // file first 4 numbers
        do {
            std::cout << "Input a positive integer: ";
            std::cin >> array[i];
        } while (array[i] < 0);

        if (array[i] == 0) {
            std::cout << "No specified subsequences of 4 elements in the sequence." << std::endl;
            return 0;
        }
    }

    // main loop
    // 1. check whether the 4 is good - output if yes
    // 2. input a number
    // 3. end if 0

    // divisible tracks the number of elements divisible by K among the last 4 inputted elements
    int divisible = 0;
    while (true) {
        // check number of elements divisible by K in the array
        for (int i = 0; i < 4; i++) {
            if (array[i] % K == 0) {
                divisible ++;
            }
        }

        // if maximum two are divisible, output the array
        if (divisible <= 2) {
            for (int i = 0; i < 4; i++) {
                std::cout << array[i] << " ";
            }
            number_of_fours ++;
            std::cout << std::endl;
        }

        // input next number
        std::cout << "Input a positive integer: ";
        do {
            std::cin >> single_number;
        } while (single_number < 0);

        // end the loop if the inputted number is 0
        if (single_number == 0) {
            break;
        }

        // otherwise add the element to the array
        for (int i = 0; i < 3; i++) {
            array[i] = array[i + 1];
        }
        array[3] = single_number;

        // reset the number of divisible
        divisible = 0;

    }

    if (!number_of_fours) {
        std::cout << "No specified subsequences of 4 elements in the sequence." << std::endl;
    }

    return 0;
}
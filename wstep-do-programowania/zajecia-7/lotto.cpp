// Napisać "grę w lotto". Użytkownik wprowadza (typuje) 6 różnych 
// liczb całkowitych z zakresu od 1 do 49. Program losuje 6 liczb
// z tego samego zakresu (musi być to losowanie bez powtórzeń!), 
// a następnie informuje użytkownika ile liczb wytypował prawidłowo. 

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {
    // user numbers input
    int array[6];
    std::cout << "Input your 6 numbers between 1 and 49." << std::endl;;
    for (int i = 0; i < 6; i++) {
        do {
            std::cout << "Input " << i + 1 << ". number: ";
            std::cin >> array[i];
        } while (array[i] < 1 || array[i] > 49);
    }

    // initialize random seed
    srand(time(NULL));

    // randomize numbers
    int correct_guesses = 0;
    for (int i = 0; i < 6; i++){
        int lotto = (rand() % 49) + 1;
        for (int j = 0; j < 6; j++) {
            if (lotto == array[j]){
                correct_guesses++;
            }
        }
    }

    // output
    std::cout << "Correct guesses: " << correct_guesses;

    return 0;
}
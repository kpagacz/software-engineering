// Napisać program pobierający od użytkownika napis i 
// wypisujący wynik zaszyfrowania tych napisów tzw. szyfrem Cezara, 
// z przesunięciem K=2. Szyfrowanie polega na zastąpieniu każdej 
// litery tekstu literą oddaloną od niej o K pozycji w alfabecie, 
// przy czym litery z końca alfabetu zastępowane są literami z jego 
// początku, a wielkie i małe litery mają zostać zachowane. Program 
// powinien umożliwiać wielokrotne pobranie napisu i wypisanie napisu 
// zaszyfrowanego, o zakończeniu pobierania decyduje użytkownik. 

#include <iostream>
#include <cstring>

int main() {
    // input
    const int array_length = 100;
    const int shift = 2;
    char text[array_length];
    char choice;

    do {
        std::cout << "Input text of maximum 99 characters (including spaces)." << std::endl;
        std::cin.getline(text, array_length);
        
        // getting length of the text
        int text_length = strlen(text);

        for (int i = 0; i < text_length; i++) {
            if (text[i] >= 'A' && text[i] <= 'Z') {
                text[i] = (text[i] - 'A' + shift) % 26 + 'A';
            } else if (text[i] >= 'a' && text[i] <= 'z'){
                text[i] = (text[i] - 'a' + shift) % 26 + 'a';
            }
        }

        std::cout << "Encoded sequence: " << text << std::endl;
        std::cout << "Input letter c to continue encoding: ";
        std::cin >> choice;
        std::cin.ignore();
    } while (choice == 'c');

    return 0;
}
// Napisać program pobierający od użytkownika napis, 
// a następnie wypisujący wynik zamiany w tym napisie 
// wszystkich małych liter na wielkie. 

#include <iostream>
#include <cstring>

int main() {
    // input
    char text[101];
    std::cout << "Input a text containing maximum 100 characters." << std::endl;
    std::cin.getline(text, 101);

    // changing lower case letters to uppercase
    for (int i = 0; text[i] != '\0'; i++) {
        if (islower(text[i])) {
            text[i] = text[i] + 'A' - 'a';
        }
    }

    std::cout << "The text with lower case letters changed to uppercase: " << std::endl;
    std::cout << text;
    return 0;
}
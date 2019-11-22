// Napisać program pobierający od użytkownika napis, 
// a następnie wypisujący wynik zamiany w tym napisie 
// wszystkich małych liter na wielkie. 
#include <iostream>
#include <cstring>

int main() {
    // input
    const int array_length = 100;
    char text[array_length];
    std::cout << "Input text of maximum 99 characters." << std::endl;
    std::cin.getline(text, array_length);

    // getting length of text
    int text_length = strlen(text);

    // changing to uppercase
    for (int i = 0; i < text_length; i++) {
        if (text[i] <= 'z' && text[i] >= 'a') {
            text[i] = text[i] - ('a' - 'A');
        }
    }

    std::cout << "All uppercase: " << text;
    return 0;
}
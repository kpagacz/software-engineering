//  Napisać program pobierający od użytkownika napis, 
//  a następnie wypisujący jego najdłuższy fragment złożony wyłącznie z wielkich liter. 
#include <iostream>
#include <cstring>

int main() {
    // input
    const int array_length = 101;
    char text[array_length];
    std::cout << "Input text of maximum 100 characters." << std::endl;
    std::cin.getline(text, array_length);

    // calculate text length
    int text_length = strlen(text);

    // calculating fragment
    int max_low_index = 0;
    int max_high_index = 0;
    int max_length = 0;
    int current_length = 0;
    int current_lower_index = 0;

    for (int i = 0; i < text_length; i++){
        if (text[i] >= 'A' && text[i] <= 'Z') {
            current_lower_index = i;
            current_length++;
            i++;
            while (text[i] >= 'A' && text[i] <= 'Z' && i < text_length) {
                current_length++;
                i++;
            }
        }
        if (current_length > max_length) {
            max_low_index = current_lower_index;
            max_high_index = current_lower_index + current_length - 1;
            max_length = current_length;
        }
        current_length = 0;
    }

    //output
    for (int i = max_low_index; i <= max_high_index; i++) {
        std::cout << text[i];
    }
    return 0;
}
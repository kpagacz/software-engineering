#include <iostream>
#include <cstring>

int main() {
    // input
    const int array_length = 100;
    char text[array_length];
    std::cout << "Input text of maximum length 99." << std::endl;
    std::cin.getline(text, array_length);

    // getting length of the input
    int text_length = strlen(text);

    // palindrome flag
    bool is_palindrome = true;

    // checking whether it is a palindrome
    for (int i = 0; i < text_length / 2; i++) {
        if (text[i] != text[text_length - 1 - i]) {
            is_palindrome = false;
            break;
        }
    }

    // output
    if (is_palindrome) {
        std::cout << "The input is a palindrome.";
    } else {
        std::cout << "The input is NOT a palindrome.";
    }

    return 0;
}
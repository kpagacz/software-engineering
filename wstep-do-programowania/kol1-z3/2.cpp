#include <iostream>
#include <cstring>
#include <cmath>


int main() {
    char text[101];
    std::cout << "Input text:" << std::endl;
    std::cin.getline(text, 100);

    int length_text = strlen(text);
    unsigned long long sum = 0;

    int position = 0;

    for (int i = length_text - 1; i >= 0; i--) {
        if (isdigit(text[i])) {
            sum += (text[i] - '0') * pow(10, position);
            position ++;
        }
    }

    std::cout << sum * sum;

    return 0;
}
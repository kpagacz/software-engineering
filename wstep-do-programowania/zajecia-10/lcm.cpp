// Napisać funkcję zwracającą najmniejszą wspólną wielokrotność 
// dwóch liczb podanych jako parametry, a następnie program 
// pobierający od użytkownika pary liczb i wypisujący NWW dla takich par. 
// Program ma umożliwiać wielokrotne pobieranie par liczb, użytkownik decyduje o zakończeniu podawania. 

#include <iostream>


int lcm(int a, int b);

int main() {
    char choice = 'c';

    int a, b;

    do {
        std::cout << "Input two integers: ";
        std::cin >> a >> b;

        std::cout << "LCM of: " << a << " and " << b << " is " << lcm(a, b) << std::endl;
        std::cout << "Input c to continue: ";
        std::cin >> choice;

    } while (choice == 'c');

    return 0;
}


int lcm(int a, int b) {
    int max = a > b ? a : b;
    int multiple = a * b;
    for (int i = max; i <= multiple; i+=max) {
        if (i % a == 0 && i % b == 0) {
            return i;
        }
    }
}


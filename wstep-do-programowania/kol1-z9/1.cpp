#include <iostream>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));

    int random;
    while (true) {
        std::cout << rand() % 25;
    }
    return 0;
}
// Napisać program pobierający od użytkownika liczby całkowite aż do 
// momentu podania zera i wypisujący te trójki kolejno podanych liczb, 
// które zawierają przynajmniej jedną liczbę pierwszą (końcowe zero nie j
// est brane pod uwagę). Program zrealizować z użyciem funkcji sprawdzającej pierwszość liczb. 

#include <iostream>
#include <cmath>

bool isPrime(int a) {
    bool prime = true;

    if (a == 1) {
        return false;
    }

    float limit = sqrt(a);

    for (int i = 2; i <= limit; i ++) {
        if (a % i == 0) {
            prime = false;
        }
    }
    return prime;
}

int main() {
    int array[3];

    std::cout << "Input integers. Zero ends inputting." << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cin >> array[i];
        if (array[i] == 0) {
            std::cout << "Not enough integeres to create a three." << std::endl;
            return 0;
        }
    }

    do {
        if (isPrime(array[0]) || isPrime(array[1]) || isPrime(array[2])) {
            std::cout << array[0] << " " << array[1] << " " << array[2] << std::endl;
        }

        for (int i = 0; i < 2; i ++) {
            array[i] = array[i + 1];
        }

        std::cin >> array[2];

    } while (array[2] != 0);


    return 0;
}
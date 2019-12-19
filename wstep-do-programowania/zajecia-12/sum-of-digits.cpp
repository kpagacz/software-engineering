// Napisać program obliczający sumę cyfr liczby naturalnej podanej jako parametr. Zadanie 
// rozwiązać za pomocą funkcji rekurencyjnej. [podpowiedź: cyfrę jedności liczby A uzyskujemy 
// obliczając resztę z dzielenia jej przez 10; liczbę A skracamy o końcową cyfrę wykonując 
// dzielenie całkowite tej liczby przez 10; czynności powtarzamy do momentu uzyskania zera ] 

#include <iostream>

int digit_sum(long long a);

int main() {
    // input
    std::cout << "Input an integer: ";
    long long a;
    std::cin >> a;

    std::cout << "Sum of digits: " << digit_sum(a);
    return 0;
}

int digit_sum(long long a) {
    if (a == 0) {
        return 0;
    }

    return (a % 10) + digit_sum(a / 10);
}

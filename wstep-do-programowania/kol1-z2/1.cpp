// 1. Pewna firma w 1 roku swojej działalności odnotowała zysk Z zł, 
// gdzie Z jest liczbą rzeczywistądodatnią. W każdym parzystym roku 
// jej zysk powiększa się o p% z poprzedniego roku. W każdymnieparzystym 
// roku zysk jest taki sam jak w roku ubiegłym. A więc np. dla Z = 10000, p = 10 w 2 roku 
// jej zysk wyniesie 11000, w 3 roku również 11000, w czwartym roku 12100, itd.   
// Napisz program pobierający od użytkownika liczby Z, p czas N (w latach) 
// działalności firmy oraz liczbę M > 0 i obliczający łączny zysk w ciągu 
// N lat oraz informujący czy przekroczy on  M.
// Przykład: dla Z=10000, p=10, N=4, M=44000 otrzymamy wynik: „Tak przekroczy i wyniesie44100 zł”.

#include <iostream>
#include <cmath>
#include <iomanip>


int main() {
    // input Z
    float Z;
    do {
        std::cout << "Input positive real number: ";
        std::cin >> Z;
    } while (Z <= 0);

    // input p
    int p;
    std::cout << "Input p: ";
    std::cin >> p;

    // input N
    int N;
    do {
        std::cout << "Input N years: ";
        std::cin >> N;
    } while (N < 0);

    // input M
    float M;
    do {
        std::cout << "Input M: ";
        std::cin >> M;
    } while (M <= 0);

    double coefficient = 1.0 + (p/100.0);
    float total_gain;
    if ((N + 1)/2 <= 1) {
        total_gain = Z + (N % 2 == 0) * Z * pow(coefficient, N/2);
    } else {
        total_gain = Z * 2.0 * ((1.0 - pow(coefficient, (N + 1)/2)) / (1.0 - coefficient)) - Z + (N % 2 == 0) * Z * pow(coefficient, N/2);
    }

    std::cout << std::setprecision(2) << std::fixed << "Total gain is: " << total_gain << ". ";
    if (total_gain > M) {
        std::cout << "It exceeded M.";
    } else {
        std::cout << "It did not exceeded M.";
    }

    return 0;
}

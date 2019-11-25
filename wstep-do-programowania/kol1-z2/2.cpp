// 2. Napisać program tworzący dynamicznie (po pobraniu od użytkownika wartości N będącej liczbącałkowitą   dodatnią)
//    tablicę   N  wartości   całkowitych.  Program  pobiera  od  użytkownika  wartościtablicy,   
//    wypisuje   jej   zawartość,   a   następnie   wypisuje   te   spośród  rozłącznych  par sąsiednich
//    elementów tej tablicy (gdzie rozłączne pary wybierane są tak, że pierwszym elementem pierwszej
//    pary   jest   pierwszy   element   tablicy,   a   w   tablicy   nieparzystej   długości   ostatni   element   nie   jest
//    elementem żadnej pary), w których przynajmniej jedna wartość jest bliska (różniąca się o mniej niż1 od) średniej wszystkich elementów tej tablicy

#include <iostream>
#include <cmath>

int main() {
    // array length
    int array_length;
    do {
        std::cout << "Input array length: ";
        std::cin >> array_length;
    } while (array_length <= 0);

    int* array = new int[array_length];

    int sum = 0;
    // input array elements
    bool first = true;
    for (int i = 0; i < array_length; i++) {
        std::cin >> array[i];
        sum += array[i];
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
    // calculate mean
    float mean = 1.0 * sum / array_length;

    // check and calculate
    for (int i = 0; i < array_length; i+=2) {
        if (abs(array[i] - mean) < 1 || abs(array[i + 1] - mean) < 1) {
            if (first) {
                std::cout << array[i] << "," << array[i + 1];
                first = false;
            } else {
                std::cout << "; " << array[i] << "," << array[i + 1];
            }
        }
    }

    return 0;
}
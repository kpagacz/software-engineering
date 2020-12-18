#include <iostream>
#include <stdio.h>
#include <ctime>

// Rozwiazanie problemu znalezienia podzbioru o najwiekszej sumie
// Podzbior nie moze zawierac sasiadujacych elementow ciagu.
// Ciag sklada sie z nieujemnych liczb calkowitych.

// Rozwiazanie rekurencyjne (znajduje tylko wartosc najwiekszej sumy)
// Od razu zauwazam, ze wielokrotnie licze najwieksza sume tego samego
// podciagu ciagu arr. Na przyklad najwieksza sume od el. 0 do el. 3:
// w przypadku gdy, start jest 0, stop 3; w przypadku, gdy start jest 0,
// stop 4 i wewnatrz petli for i = 4.
int max_sum_subset_rec(int start, int stop, int *arr) {
    if(start > stop)
        return 0;
    if(start == stop)
        return arr[start];

    int max = INT_MIN;
    int current_max = 0;

    for(int i = start; i <= stop; i++) {
        current_max = max_sum_subset_rec(start, i - 1, arr) + max_sum_subset_rec(i + 1, stop, arr);
        if (current_max > max)
            max = current_max;
    }

    return max;
}

// Moglbym od razu policzyc wartosci najwiekszych sum dla wszystkich mozliwych
// podciagow tego ciagu, zaczynajac od podciagow o dlugosci 1 i konczac na
// podciagu od start do stop. W tym celu zadeklaruje tablice dwuwymiarowa,
// w ktorej bede przechowywal wartosci najwiekszych sum podzbiorow podciagow arr.
// tablica_maksow[i][j] bedzie zawierac najwieksza sume podzbioru 
// mozliwa do osiagniecia na podciagu zaczynajacym sie od elementu i i konczacym
// na j.
int max_sum_subset_it(int start, int stop, int *arr) {
    int** max_values = new int*[stop - start + 3];

    for(int i = 0; i < stop - start + 3; i++) {
        max_values[i] = new int[stop - start + 3];
        for(int j = 0; j < stop - start + 3; j++)
            max_values[i][j] = 0;
    }

    for(int i = start + 1, j = start + 1; j <= stop + 1; ++i, ++j)
        max_values[i][j] = arr[i - 1];
    for(int sub_distance = 1; sub_distance <= stop - start; sub_distance++) {
        for(int i = start + 1, j = start + 1 + sub_distance; j <= stop + 1; ++i, ++j) {
            int curr = 0;
            int not_taken = 0;
            for(int k = i; k <= j; k++) {
                curr = max_values[i][k - 1] + max_values[k + 1][j];
                if(curr >= max_values[i][j])
                    max_values[i][j] = curr;
            }
        }
    }

    int return_value = max_values[start + 1][stop + 1];
    for(int i = 0; i < stop - start + 3; i++)
        delete [] max_values[i];
    delete [] max_values;

    return return_value;
}

// Kolejny pomysl polega na sprawdzaniu, czy oplacalo sie wziac poprzedni
// element czy nie. Obserwacja jest taka, ze wybor elementu zalezy tylko
// od jego sasiadow, wiec mozna przejsc caly ciag, patrzac, czy kazdy
// element jest "warty" wziecia go
int max_sum_subset_it2(int start, int stop, int* arr) {
    int max_with_last_taken = arr[start], max_with_last_not_taken = 0, curr_max;

    for(int i = start + 1; i <= stop; i++) {
        curr_max = (max_with_last_taken > max_with_last_not_taken) ? max_with_last_taken : max_with_last_not_taken;
        max_with_last_taken = max_with_last_not_taken + arr[i];
        max_with_last_not_taken = curr_max;
    }

    return ((max_with_last_taken > max_with_last_not_taken) ? max_with_last_taken : max_with_last_not_taken);
}


int main() {
    srand(time(NULL));
    // testowanie wersji rekurencyjnej
    std::cout << "Reccurent solution testing:\n";
    int arr1[] = {7};
    std::cout << max_sum_subset_rec(0, 0, arr1) << '\n';
    int arr2[] = {7, 1, 7};
    std::cout << max_sum_subset_rec(0, 2, arr2) << '\n';
    int arr3[] = {7, 1, 1, 7};
    std::cout << max_sum_subset_rec(0, 3, arr3) << '\n';
    int arr4[] = {1, 1, 1, 1};
    std::cout << max_sum_subset_rec(0, 3, arr4) << '\n';
    int arr5[] = {1, 1, 1, 1, 1};
    std::cout << max_sum_subset_rec(0, 4, arr5) << '\n';
    int arr6[] = {7, 1};
    std::cout << max_sum_subset_rec(0, 1, arr6) << "\n";
    int arr8[] = {1, 1, 1};
    std::cout << max_sum_subset_rec(0, 2, arr8) << "\n";
    

    // testowanie wersji iteracyjnej
    std::cout << "Iterative solution testing:\n";
    std::cout << max_sum_subset_it(0, 0, arr1) << "\n";
    std::cout << max_sum_subset_it(0, 2, arr2) << '\n';
    std::cout << max_sum_subset_it(0, 3, arr3) << '\n';
    std::cout << max_sum_subset_it(0, 3, arr4) << '\n';
    std::cout << max_sum_subset_it(0, 4, arr5) << '\n';
    std::cout << max_sum_subset_it(0, 1, arr6) << "\n";
    std::cout << max_sum_subset_it(0, 2, arr8) << "\n";

    std::cout << "Iterative solution testing 2:\n";
    std::cout << max_sum_subset_it2(0, 0, arr1) << "\n";
    std::cout << max_sum_subset_it2(0, 2, arr2) << '\n';
    std::cout << max_sum_subset_it2(0, 3, arr3) << '\n';
    std::cout << max_sum_subset_it2(0, 3, arr4) << '\n';
    std::cout << max_sum_subset_it2(0, 4, arr5) << '\n';
    std::cout << max_sum_subset_it2(0, 1, arr6) << "\n";
    std::cout << max_sum_subset_it2(0, 2, arr8) << "\n";

    // stress test wersji rekurencyjnej
    // std::cout << "Stress testing recurrence solution: \n";
    // int *arr7 = new int[100];
    // for(int i = 0; i < 100; i++) {
    //     arr7[i] = rand() % 100;
    // }
    // for(int i = 0; i < 100; i++) {
    //     std::cout << arr7[i] << " ";
    // }
    // std::cout << "\n";
    // for(int i = 0; i < 25; i++) {
    //     std::cout << max_sum_subset_rec(0, i, arr7) << " "; // zajmuje kolo 25 sekund na mojej maszynie przy i = 25
    //     std::cout << max_sum_subset_it(0, i, arr7) << "\n"; // zajmuje mniej niz sekunde na mojej maszynie przy i = 25
    // }
    // delete [] arr7;

    return 0;
}
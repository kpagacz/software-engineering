#include<iostream>


void Pobierz(int* array, int length);
void Wypisz(int* array, int length);
void PrzestawMale(int* array, int length);
int* UsunWielkaSume(int* array, int length, int& new_length);
void PrzestawElementy(int* array, int ind1, int ind2);


int main() {
    // input length
    std::cout << "Input array length: ";
    int length;
    std::cin >> length;

    // array declaration
    int* array = new int[length];

    // input elements
    std::cout << "Input array elements:" << std::endl;
    Pobierz(array, length);

    // output elements
    std::cout << "Array is: " << std::endl;
    Wypisz(array, length);

    // usunwielkasume
    int new_length;
    int* new_array = UsunWielkaSume(array, length, new_length);

    // output
    std::cout << "Array is: " << std::endl;
    Wypisz(new_array, new_length);   

    // przestawmale
    PrzestawMale(array, length);

    // output
    std::cout << "Array is: " << std::endl;
    Wypisz(array, length);   

    int tab[0];
    std::cout << tab[0];

    delete [] array;
    return 0;
}

void Pobierz(int* array, int length) {
    for (int i = 0; i < length; i++) {
        std::cin >> array[i];
    }
}

void Wypisz(int* array, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void PrzestawElementy(int* array, int ind1, int ind2) {
    int c = array[ind2];
    for (int i = ind2; i > ind1; i--) {
        array[i] = array[i - 1];
    }
    array[ind1] = c;
}

void PrzestawMale(int* array, int length) {
    int licznik = 0;
    int min = array[0];

    // znajdywania minimum
    for (int i = 1; i < length; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }

    // zamienianie minimów z początkowymi
    for (int i = 0; i < length; i++) {
        if (array[i] == min) {
            PrzestawElementy(array, licznik, i);
            licznik++;
        }
    }
}

int* UsunWielkaSume(int* array, int length, int& new_length) {
    int max_suma = 0;
    int suma_length;
    int suma_poczatek = -1;
    int suma = 0;

    // znajdywanie wielkiej sumy
    for (int i = 0; i < length; i++) {
        suma += array[i];

        if (suma < 0) {
            suma = 0;
            suma_poczatek = i;
        } else {
            if (suma > max_suma) {
                max_suma = suma;
                suma_length = i - suma_poczatek;
            }
        }
    }

    int suma_koniec = suma_poczatek + suma_length + 1;

    new_length = length - suma_length;

    // zwróć pustą tablicę dla samych dodatnich?
    if (new_length == 0) {
        int* new_array = new int[length] {0};
        return new_array;
    }

    int* new_array = new int[new_length];

    int indeks = 0;

    for (int i = 0; i < length; i++) {
        if (i <= suma_poczatek || i >= suma_koniec) {
            new_array[indeks] = array[i];
            indeks++;
        }
    }

    return new_array;
}
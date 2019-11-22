// Jedna z metod sortowania tablic działa w następujący sposób:

//     sprawdzamy, czy wartości w elementach pierwszym i drugim stoją w prawidłowym porządku, 
//     jeśli nie, to zamieniamy je miejscami;
//     powtarzamy powyższe dla elementów drugiego i trzeciego, 
//     potem trzeciego i czwartego itd, aż dojdziemy do końca tablicy
//     ----~> powyższy ciąg czynności zapewni nam, że największa (a przy sortowaniu nierosnącym - najmniejsza) 
//     wartość znajdzie się na ostatniej pozycji tablicy;
//     powtarzamy kroki 1-2 dla coraz krótszych fragmentów tablicy początkowej: 
//     najpierw dla fragmentu odpowiadającego tej tablicy bez ostatniego elementu, 
//     potem dla fragmentu odpowiadającego tablicy początkowej bez dwóch ostatnich elementów itd;
//     ---~-> każdy z kroków powoduje, że największa (lub - przy sortowaniu nierosnącym - najmniejsza) wartość 
//     znajdująca się w rozpatrywanym fragmencie wywędruje na jego koniec;
//     ostatnim krokiem będzie wykonanie powyższych działań dla fragmentu tablicy 
//     złożonego z dwóch pierwszych elementów. 

// Napisać program losujący zawartość tablicy liczb całkowitych o podanej przez użytkownika długości, 
// a następnie sortujący ją nierosnąco lub niemalejąco (o sposobie sortowania decyduje użytkownik). 


#include <iostream>

bool comparator(int value1, int value2, char decision) {
    if (decision == 'i') {
        return value2 > value1;
    } else {
        return value1 > value2;
    }
}


int main() {
    // input
    std::cout << "Input array length: ";
    int array_length;
    std::cin >> array_length;

    char decision;
    do {
        std::cout << "Input order: (i)ncreasing or (d)ecreasing: ";
        std::cin >> decision;
    } while (decision != 'd' &&decision != 'i');

    std::cout << "Input array elements: ";
    int* array = new int[array_length];
    for (int i = 0; i < array_length; i++) {
        std::cin >> array[i];
    }

    // sorting
    for (int i = array_length - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (!comparator(array[j], array[j + 1], decision)) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < array_length; i++) {
        std::cout << array[i] << " ";
    }

    delete [] array;
    return 0;
}
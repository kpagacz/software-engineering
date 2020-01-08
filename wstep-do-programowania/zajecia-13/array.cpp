// Napisać program zawierający następujące funkcje:

//     funkcję pobierającą zawartość tablicy liczb całkowitych podanej jako parametr, o długości podanej jako parametr;
//     funkcję wypisującą zawartość tablicy liczb całkowitych podanej jako parametr;
//     funkcję ZamienNaPodzielnik zamieniający wartość parametru przekazującego dodatnią liczbę całkowitą na najmniejszy (i różny od 1, dla liczb większych od 1) podzielnik tej liczby;
//     funkcję ZamienDodatnie modyfikująca tablicę podaną jako parametr poprzez zamianę w niej wszystkich liczb dodatnich na ich najmniejsze podzielniki różne od 1 (jeśli taki podzielnik istnieje). Zamianę wykonać za pomocą funkcji ZamienNaPodzielnik;
//     Funkcję TablicaDuzych zwracającą tablicę powstałą z tablicy podanej jako parametr poprzez przekopiowanie do niej wszystkich tych elementów z tablicy wejściowej, które są nie mniejsze od wszystkich poprzedzających je wartości w tej tablicy (przykład: dla tablicy 2,4,4,1,7,2,7,3,5,9 wynikiem jest tablica 2,4,4,7,7,9, dla tablicy 3,2,1 wynikiem jest tablica zawierająca tylko wartość 3).
//     funkcję NajdluzszaPodtablicaWiekszychPodwojona zwracającą tablicę powstałą z tablicy podanej jako parametr poprzez przekopiowanie do tablicy wynikowej najdłuższej podtablicy (tj. ciągu sąsiednich elementów tej tablicy) zawierającej wartości większe od liczby całkowitej G podanej jako drugi parametr, a następnie wydłużenie tej tablicy o drugi identyczny fragment (przykład: dla tablicy 4,5,-2,1,2,3,4,4,5,3,3,4,6,8,7,-2,2,3,1 i G=3 wynikiem będzie tablica 4,6,8,7,4,6,8,7, dla tej samej tablicy i G=7 – tablica zawierająca tylko wartości 8,8). Jeśli funkcja wymaga dodatkowych parametrów, należy je dodać 

// oraz program tworzący tablicę liczb całkowitych o długości podanej przez użytkownika i testujący powyższe funkcje. 


#include <iostream>
#include <cmath>

void inputArrayElements(int* arr, const int& length) {
    std::cout << "Input array elements:" << std::endl;
    for (int i = 0; i < length; i++) {
        std::cin >> arr[i];
    }
}


void outputArray(int* arr, const int& length) {
    std::cout << "Array elements are: " << std::endl;
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void changeToDivisor(int& n) {
    int divisor = 2;
    while (divisor <= sqrt(n)) {
        if (n % divisor == 0) {
            n = divisor;
            return;
        }
        divisor ++;
    }
}

void replacePositives(int* arr, const int& length) {
    for (int i = 0; i < length; i++) {
        if (arr[i] > 0) {
            changeToDivisor(arr[i]);
        }
    }
}

int* arrayOfBig(int* arr, const int& length, int& new_length) {
    bool* to_copy = new bool[length];
    to_copy[0] = true;
    int index_last_to_copy = 0;

    for (int i = 1; i < length; i ++) {
        if (arr[i] >= arr[index_last_to_copy]) {
            to_copy[i] = true;
            index_last_to_copy = i;
        } else {
            to_copy[i] = false;
        }
    }

    // counting the new length
    new_length = 0;
    for (int i = 0; i < length; i++) {
        if(to_copy[i]) {
            new_length++;
        }
    }

    // declaring new array
    int* new_array = new int[new_length];
    
    // copying elements to new array
    int new_index = 0;
    for (int i = 0; i < length; i++) {
        if (to_copy[i]) {
            new_array[new_index] = arr[i];
            new_index++;
        }
    }

    return new_array;
}

int* theLongestSubarrayDoubled(int* array, const int& length, int threshold, int& new_length) {
    int longest = 0;
    int start_of_longest = 0;
    int current_length = 0;

    for (int i = 0; i < length; i++) {
        if (array[i] > threshold) {
            current_length++;
            if (current_length > longest) {
                start_of_longest = i - current_length + 1;
                longest = current_length;
            }
        } else {
            current_length = 0;
        }
    }

    // init new array
    new_length = 2 * longest;
    int* longest_array = new int[new_length];

    for (int i = 0; i < longest; i ++) {
        longest_array[i] = array[start_of_longest + i];
        longest_array[longest + i] = array[start_of_longest + i];
    }

    return longest_array;
}


int main() {
    // input array length
    int length;
    std::cout << "Input array length: ";
    std::cin >> length;

    // array init
    int* array = new int[length];

    // input elements
    inputArrayElements(array, length);
    outputArray(array, length);

    // replace positives
    replacePositives(array, length);
    std::cout << "After replacing positives: " << std::endl;
    outputArray(array, length);

    // bigArray
    int big_length;
    int* big_array = arrayOfBig(array, length, big_length);
    std::cout << "Array of big elements is:" << std::endl;
    outputArray(big_array, big_length);


    // the longest subarray of elements greater than a threshold number
    int T = 3;
    int longest_length;
    int* longest_array = theLongestSubarrayDoubled(array, length, T, longest_length);
    std::cout << "The longest subarray doubled: " << std::endl;
    outputArray(longest_array, longest_length);

    delete [] array;
    return 0;
}
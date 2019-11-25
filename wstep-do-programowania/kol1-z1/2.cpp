// 2. Napisać program tworzący dynamicznie N – elementową  
// tablicę liczb całkowitych, gdzie N > 0jest liczbą całkowitą 
// podaną przez użytkownika. Wartości tablicy są podawane przez użytkownika,
// a   następnie   wypisywane.   Program   ma   wypisać   wszystkie   takie   
// ciągi     kolejnych   elementów   tejtablicy, których długość przekracza M 
// oraz wszystkie elementy w ciągu są liczbami parzystymi. M jest   liczbą   
// całkowitą   dodatnią   podaną   przez   użytkownika.   Bierzemy   pod   
// uwagę   tylko   ciągi nierozszerzalne, tzn. takie, że nie możemy ich rozszerzyć 
// o liczbę parzystą „ani z lewej ani z prawejstrony ciągu”. 
// Np. w ciągu 1 2 4  6 5 nierozszerzalny ciąg kolejnych liczb parzystych to 2 4 6 , 
// ciągi2 4 i 4 6 byłyby rozszerzalne. Jeśli w tablicy nie ma ciągów spełniających te warunki, 
// programzwraca informację: „Brak takich ciągów.”.
// Przykład: N = 13, M = 2;  tablica: 2 3 4 6 8 3 8 6 3 0 2 10 4; odpowiedź: 4 6 8, 0 2 10 4

#include <iostream>

int main() {
    // input number M
    int M;
    std::cout << "Input M: ";
    std::cin >> M;

    // input array_length of array
    int array_length;
    std::cout << "Input array length: ";
    std::cin >> array_length;

    // define array
    int* array = new int[array_length];

    // input array elements
    for (int i = 0; i < array_length; i++) {
        std::cin >> array[i];
    }

    int ind_ = 0;
    int subseq_length = 0;
    int subseq_counter = 0;


    while (ind_ < array_length) {
        while (array[ind_] % 2 != 0) {
            ind_ ++;
        }


        while (ind_ + subseq_length < array_length) {
            if (array[ind_+subseq_length] % 2 == 0) {
                subseq_length ++;
            } else {
                break;
            }
        }


        if (subseq_length > M) {
            if (subseq_counter > 0) {
                std::cout << ", ";
            }
            std::cout << array[ind_];
            for (int i = 1; i < subseq_length; i++) {
                std::cout << " " << array[ind_ + i];
            }
            subseq_counter++;
        }

        ind_ = ind_ + subseq_length + 1;
        subseq_length = 0;
    }

    if (!subseq_counter) {
        std::cout << "No such subsequences." << std::endl;
    }

    delete [] array;
    return 0;
}
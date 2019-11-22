// Napisać program wczytujący zawartość tablicy liczb całkowitych o 
// długości podanej przez użytkownika, a następnie, w zależności od decyzji użytkownika:

//     oblicza liczbę parzystych oraz liczbę nieparzystych elementów tablicy;
//     oblicza długość najdłuższego fragmentu tablicy, w którym wszystkie elementy są dodatnie;
//     wczytuje dwie liczby całkowite L i P (liczby mają być dodatnie i nie większe od 
//         długości tablicy), a następnie odwraca kolejność elementów we fragmencie wyznaczonym przez wartości tych zmiennych. 

// Program powinien pozwalać na wielokrotne wybieranie czynności do wykonania. 

#include <iostream>

int main() {
    // input array length
    std::cout << "Input array length: ";
    int array_length;
    std::cin >> array_length;

    // input array elements
    int* array = new int[array_length];
    std::cout << "Input array elements: ";
    for (int i = 0; i < array_length; i++) {
        std::cin >> array[i];
    }

    // odd and even counter
    int even_counter = 0;
    for (int i = 0; i < array_length; i++) {
        if (array[i] % 2 == 0) {
            even_counter++;
        }
    }

    std::cout << "Number of even elements: " << even_counter << ". Number of odd elements: " << array_length - even_counter << std::endl;

    // longest positive streak
    int max_positive_streak = 0;
    int current_streak = 0;
    int current_ind = 0;
    int max_positive_streak_last_ind = 0;

    while (current_ind < array_length) {
        while (array[current_ind] > 0) {
            current_streak++;
            current_ind++;
        }

        if (current_streak > max_positive_streak) {
            max_positive_streak = current_streak;
            max_positive_streak_last_ind = current_ind - 1;
        }
        current_streak = 0;
        current_ind++;
    }

    if (current_streak > max_positive_streak) {
        max_positive_streak = current_streak;
        max_positive_streak_last_ind = current_ind - 1;
    }

    std::cout << "Maximum length of a positive streak is: " << max_positive_streak << std::endl;

    // reverse fragment of array
    int l, r;
    do {
        std::cout << "Input left and right indices of a fragment, which elements will be reversed: ";
        std::cin >> l >> r;
    } while (l > r || l < 0 || r < 0 || l >= array_length || r >= array_length);

    int fragment_length = r - l + 1;

    for (int i = 0; i < fragment_length / 2; i++) {
        int temp = array[l + i];
        array[l + i] = array[r - i];
        array[r - i] = temp;
    }

    std::cout << "Array currently is: ";
    for (int i = 0; i < array_length; i++) {
        std::cout << array[i] << " ";
    }

    delete [] array;
    return 0;
}
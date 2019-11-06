// Napisać program, który pobiera od użytkownika 5 liczb całkowitych, 
// a następnie wypisuje tabelkę zawierającą iloczyny tych liczb. 
// Przykładowo, dla liczb 1,2,3,1,2 dostaniemy tabelkę

//    1  2  3  1  2
// 1  1  2  3  1  2
// 2  2  4  6  2  4
// 3  3  6  9  3  6
// 1  1  2  3  1  2
// 2  2  4  6  2  4

#include <iostream>
#include <iomanip>

int main() {
    // input
    int* array = new int[5];
    const int width = 7;

    // filling table with 5 values
    std::cout << "Input 5 integers: ";
    for (int i = 0; i < 5; i ++) {
        std::cin >> array[i];
    }


    // output first row
    std::cout << std::setw(width) << " ";
    for (int i = 0; i < 5; i++) {
        std::cout << std::setw(width) << array[i];
    }
    std::cout << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << std::setw(width) << array[i];
        for (int j = 0; j < 5; j++) {
            std::cout << std::setw(width) << array[i] * array[j];
        }
        std::cout << std::endl;
    }

    delete [] array;
    return 0;
}
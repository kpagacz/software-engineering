// Napisać program pobierający od użytkownika dwie 
// macierze kwadratowe o podanym przez użytkownika 
// rozmiarze i tworzący macierz będącą ich sumą 
// oraz macierz będącą ich iloczynem. 

#include <iostream>
#include <iomanip>

int row_times_column(int* m1, int* m2, const int& row, const int& column, const int& size) {
    // function which calculates multiplication of a single column and a single verse of
    // to matrices
    // returns the result of the multiplication
    int result = 0;

    for (int i = 0; i < size; i ++) {
        result += m1[row * size + i] * m2[i * size + column];
    }

    return result;
}

int main() {
    // config
    const int element_width = 4;

    // input
    int size;
    std::cout << "Input the numer of the columns in the two matrices: ";
    std::cin >> size;

    // matrices definition
    int elements = size * size;
    int* m1 = new int[elements];
    int* m2 = new int[elements];

    // input the first matrix
    std::cout << "Input the first matrix." << std::endl;
    for (int i = 0; i < elements; i++) {
        std::cin >> m1[i];
    }

    // input the second matrix
    std::cout << "Input the second matrix." << std::endl;
    for (int i = 0; i < elements; i++) {
        std::cin >> m2[i];
    }

    // addition
    int* addition = new int[elements];
    for (int i = 0; i < elements; i ++) {
        addition[i] = m1[i] + m2[i];
    }

    // output addition result
    std::cout << "First matrix + second matrix: " << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::setw(element_width) << addition[i * size + j];
        }
        std::cout << std::endl;
    }

    // multiplication
    int* multiplication = new int[elements];
    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size; j++) {
            multiplication[i * size + j] = row_times_column(m1, m2, i, j, size);
        }
    }

    // output multiplication result
    std::cout << "First matrix * second matrix: " << std::endl;
    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::setw(element_width) << multiplication[i * size + j];
        }
        std::cout << std::endl;
    }

    delete [] m1, m2, addition, multiplication;
    return 0;
}
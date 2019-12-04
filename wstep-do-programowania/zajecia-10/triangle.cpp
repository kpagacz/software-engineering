// Napisać program pobierający od użytkownika liczby całkowite aż do podania liczby 0 kończącej pobieranie. 
// Program sprawdza, czy każda trójka kolejno podanych liczb może stanowić długości boków trójkąta, 
// i jeśli tak - wypisuje jego pole i obwód. Końcowe zero nie jest brane pod uwagę. Jeśli podano mniej niż 
// trzy liczby, program wypisuje odpowiedni komunikat.
// Program należy zrealizować za pomocą funkcji:

//     funkcji Czy_Trojkat, zwracającej wartość mówiącą, czy liczby całkowite podane jako parametry mogą być długościami boków trójkąta
//     funkcji zwracającej obwód trójkąta o bokach podanych jako parametry,
//     funkcji zwracającej pole trójkąta o bokach podanych jako parametry. 

#include <iostream>
#include <cmath>

bool is_triangle(int a, int b, int c) {
    // check triangle inequality
    bool triangle = true;

    if (a + b <= c || a + c < b || b + c < a) {
        triangle = false;
    }
    return triangle;
}


int triangle_circ(int a, int b, int c) {
    // triangle circumference
    return a + b + c;
}

float triangle_area(int a, int b, int c) {
    // heron's formula
    float area;
    area = sqrt((a + b + c) * (a + b - c) * (a + c - b) * (b + c - a)) / 4;
    return area;
}


int main() {
    int a, b, c;

    while (true) {
        std::cout << "Input three integers: ";
        std::cin >> a;
        if (a == 0 ) {
            std::cout << "Not enough integers to construct a triangle. Zero ends the input." << std::endl;
            break;
        }

        std::cin >> b;
        if (b == 0 ) {
            std::cout << "Not enough integers to construct a triangle. Zero ends the input." << std::endl;
            break;
        }

        std::cin >> c;
        if (c == 0 ) {
            std::cout << "Not enough integers to construct a triangle. Zero ends the input." << std::endl;
            break;
        }

        if(is_triangle(a, b, c)) {
            std::cout << "Can construct a triangle." << std::endl;
            std::cout << "Triangle circumference: " << triangle_circ(a, b, c) << ". Triangle area: " << triangle_area(a, b, c) << std::endl;
        } else {
            std::cout << "Cannot construct a triangle." << std::endl;
        }
    }

    return 0;
}

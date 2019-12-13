// Napisać program zawierający następujące funkcje:
// funkcję wypisz_menu wypisującą menu umożliwiające wybranie wykonania obliczeń dla prostokąta, kwadratu albo koła
// funkcję Oblicz_wszystko przyjmującą bok kwadratu (liczbę całkowitą) i zwracającą (poprzez parametry) jego pole i obwód (liczby całkowite)
// funkcję Oblicz_wszystko przyjmującą boki prostokąta (liczby całkowite) i zwracającą (poprzez parametry) jego pole i obwód (liczby całkowite)
// funkcję Oblicz_wszystko przyjmującą promień koła (liczbę całkowitą) i zwracającą (poprzez parametry) jego pole i obwód (liczby rzeczywiste)
// oraz program wykorzystujący te funkcje do wielokrotnego wybierania obliczanej figury, pobierania jej danych i wypisywania pola i obwodu.


/* TO-DO
- input validation (currently accepts negative values of the sides and radius)
*/



#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>

char output_menu();
void calculate_everything(int side, float& area, float& circumference);
void calculate_everything(int side1, int side2, float& area, float& circumference);
void calculate_everything(float radius, float& area, float& circumference);

int main() {
    char choice;
    float area, circumference;
    int first, second;
    float radius;

    while (choice = output_menu()) {
        switch (choice) {
            case 's':
                std::cout << "Input side length of the square: ";
                std::cin >> first;
                calculate_everything(first, area, circumference);
                break;
            case 'r':
                std::cout << "Input two sides of the rectangle: ";
                std::cin >> first >> second;
                calculate_everything(first, second, area, circumference);
                break;
            case 'c':
                std::cout << "Input radius of the circle: ";
                std::cin >> radius;
                calculate_everything(radius, area, circumference);
                break;
            default:
                continue;
        }
        std::cout << std::setprecision(2) << std::fixed << "Area: " << area << ". Circumference: " << circumference << std::endl;
    }

    return 0;
}

char output_menu() {
    // outputs menu only
    char choice;
    std::cout << "Please input letter s or letter r or letter c to do calculations for a (s)quare, (r)ectangle or (c)ircle.: ";
    std::cin >> choice;

    return choice;
}


void calculate_everything(int side, float& area, float& circumference) {
    area = side * side;
    circumference = 4 * side;
}

void calculate_everything(int side1, int side2, float& area, float& circumference) {
    area = side1 * side2;
    circumference = 2 * (side1 + side2);
}

void calculate_everything(float radius, float& area, float& circumference) {
    area = radius * radius * M_PI;
    circumference = 2 * M_PI * radius;
}
#include <iostream>
#include "ulamki.hpp"

int main() {
    Ulamek domyslny;
    domyslny.Wypisz();

    // Powinno zwrocic wyjatek
    // Ulamek mianownik_zero(7, 0);

    Ulamek licznik_ujemny (-1, 1);
    licznik_ujemny.Wypisz();

    Ulamek mianownik_ujemny (1, -1);
    mianownik_ujemny.Wypisz();

    Ulamek licznik_mianownik_ujemny(-1, -1);
    licznik_mianownik_ujemny.Wypisz();

    // testowanie skracania ulamka
    Ulamek do_skrocenia(10, 20);
    do_skrocenia.SkrocUlamek();
    std::cout << "Powinno wypisac 1 / 2: ";
    do_skrocenia.Wypisz();
    do_skrocenia.setLicznik(1);
    do_skrocenia.setMianownik(3);
    do_skrocenia.SkrocUlamek();
    std::cout << "Powinno wypisac 1 / 3: ";
    do_skrocenia.Wypisz();

    // testowanie porownywania ulamka
    Ulamek mniejszy(1, 3);
    Ulamek wiekszy(2, 3);
    if (mniejszy < wiekszy) {
        std::cout << "Mniejszy ulamek jest mniejszy!" << std::endl;
    } else {
        std::cout << "Mniejszy ulamek jest wiekszy :(:" << std::endl;
    }

    if (mniejszy <= wiekszy) {
        std::cout << "Operator <= dziala." << std::endl;
    }

    if (wiekszy >= mniejszy) {
        std::cout << "Operator >= dziala." << std::endl;
    }

    if (wiekszy > mniejszy) {
        std::cout << "Operator > dziala." << std::endl;
    }

    
    return 0;
}
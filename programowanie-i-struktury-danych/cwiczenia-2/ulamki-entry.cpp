#include <iostream>
#include "ulamki.hpp"

int main() {
    Ulamek domyslny;
    domyslny.Wypisz();

    try
    {
        Ulamek mianownik_zero(7, 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

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

    // testowanie rownowaznosci ulamkow
    Ulamek rowny1(1, 2);
    Ulamek rowny2(2, 4);
    if (rowny1 == rowny2) {
        std::cout << "Testowanie rownowaznosci ulamkow: sukces." << std::endl;
    } else {
        std::cout << "Testowanie rownowaznosci ulamkow: porazka." << std::endl;
    }

    // testowanie operatorow binarnych
    Ulamek dodawanie11(1, 3);
    Ulamek dodawanie12(1, 9);
    Ulamek dodawanie_wynik1 = dodawanie11 + dodawanie12;
    dodawanie_wynik1.SkrocUlamek();
    if (dodawanie_wynik1.getLicznik() == 4 && dodawanie_wynik1.getMianownik() == 9) {
        std::cout << "Testowanie dodawania ulamkow: sukces." << std::endl;
    } else {
        std::cout << "Testowanie dodawania ulamkow: porazka." << std::endl;
        dodawanie_wynik1.Wypisz();
    }

    Ulamek mnozenie11(1, 3);
    Ulamek mnozenie12(1, 2);
    Ulamek mnozenie_wynik1 = mnozenie11 * mnozenie12;
    if (mnozenie_wynik1.getLicznik() == 1 && mnozenie_wynik1.getMianownik() == 6) {
        std::cout << "Testowanie mnozenia ulamkow: sukces." << std::endl;
    } else {
        std::cout << "Testowanie mnozenia ulamkow: porazka." << std::endl;
        mnozenie_wynik1.Wypisz();
    }

    Ulamek dzielenie_wyniki = mnozenie11 / mnozenie12;
    if (dzielenie_wyniki.getLicznik() == 2 && dzielenie_wyniki.getMianownik() == 3) {
        std::cout << "Testowanie dzielenia ulamkow: sukces." << std::endl;
    } else {
        std::cout << "Testowanie dzielenia ulamkow: porazka." << std::endl;
        dzielenie_wyniki.Wypisz();
    }
    
    return 0;
}
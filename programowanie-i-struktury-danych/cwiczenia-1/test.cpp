#include <iostream>
#include "cwiczenia-1.hpp"


int main() {

    Osoba o;
    o.Imie = "Ola";
    o.Nazwisko = "Ryk";
    o.wypisz();
    o.ZmienNazwisko("Nowe");
    o.ZmienWzrost(175);
    o.wypisz();
    std::cout << o.czyKobieta() << std::endl;
    Osoba k("Anna", "Swierk", "92070812185", 198);
    k.wypisz();
    return 0;
}
#include <iostream>
#include "cwiczenia-1.hpp"
#include <iomanip>


int main() {
    Osoba o;
    o.Imie = "Ola";
    o.Nazwisko = "Ryk";
    o.wypisz();
    o.ZmienNazwisko("Nowe");
    o.ZmienWzrost(175);
    o.wypisz();
    std::cout << o.czyKobieta() << std::endl;
    std::cout << o.RokUrodzenia() << " " << o.MiesiacUrodzenia() << " " << o.DzienUrodzenia() << std::endl;

    Osoba k("Anna", "Swierk", "92070812185", 198);
    Osoba j("Tomek", "Jodla", "12345678911", 220);

    k.wypisz();
    j.wypisz();

    // testowanie grupy
    Grupa moja_grupa;
    moja_grupa.DodajOsobe(o);
    moja_grupa.DodajOsobe(k);
    moja_grupa.DodajOsobe(j);

    moja_grupa.Wypisz();

    if (moja_grupa.CzyJestMezczyzna()) {
        std::cout << "W grupie jest mezczyzna." << std::endl;
    }
    
    std::cout << "Urodzenie w lipcu:" << std::endl;
    moja_grupa.UrodzoneWMiesiacu(7);

    std::cout << "Sredni wzrost: " << std::fixed << std::setprecision(2) << moja_grupa.SredniWzrost() << std::endl;

    std::cout << "Najmlodsza osoba: " << std::endl;
    moja_grupa.Najmlodsza().wypisz();

    std::cout << "Najstarsza osoba: " << std::endl;
    moja_grupa.Najstarsza().wypisz();

    std::cout << "Nazwiska: " << std::endl;
    moja_grupa.WypiszNazwiska();

    return 0;
}
/*
    Napisać bibliotekę udostępniającą:
        typ strukturalny Osoba o polach Imie, Nazwisko (ciągi znaków), PESEL (tablica cyfr) i Wzrost (liczba całkowita nieujemna)
        konstruktor osoby przyjmujący jako parametry trzy ciągi znaków oznaczające odpowiednio imię, nazwisko i PESEL osoby oraz liczbę oznaczającą jej wzrost;
        funkcję (metodę) wypisującą dane osoby;
        funkcję (metodę) ZmienWzrost przypisującą wzrostowi osoby wartość podaną jako parametr;
        funkcję (metodę) ZmienNazwisko zmieniającą nazwisko osoby na wartość podaną jako parametr;
        funkcje (metody) czyKobieta i czyMezczyzna zwracające wartości logiczne informujące o płci osoby,
        funkcje (metody) RokUrodzenia, MiesiacUrodzenia i DzienUrodzenia zwracające odpowiednie informacje dotyczące daty urodzenia osoby 
    oraz program testujący działanie funkcji udostępnionych przez bibliotekę.
    Rozszerzyć bibliotekę tak aby udostępniała:
        typ strukturalny Grupa umożliwiający przechowanie grupy osób, liczącej maksymalnie 30 członków;
        konstruktor (bezparametrowy) grupy osób, tworzący grupę pustą;
        funkcję (metodę) DodajOsobe dodającą do grupy osobę (typu Osoba) podaną jako parametr;
        funkcję (metodę) Wypisz wypisującą grupę osób podaną jako parametr;
        funkcję (metodę) CzyJestMezczyzna zwracającą wartość logiczną mówiącą czy w grupie jest przynajmniej jeden mężczyzna;
        funkcję (metodę) wypisującą wszystkie osoby z grupy urodzone w miesiącu podanym jako parametr;
        funkcję (metodę) SredniWzrost zwracającą średni wzrost osób w grupie;
        funkcje (metody) Najstarsza i Najmlodsza zwracające odpowiednio najstarszą i najmłodszą osobę w grupie;
        funkcję (metodę) wypisującą wszystkie nazwiska osób w grupie;
        funkcję (metodę) zwracającą nową grupę utworzoną z osób należących do grupy podanej jako parametr i równocześnie urodzonych w latach R1-R2, gdzie R1 i R2 są drugim i trzecim parametrem funkcji. 
    Przetestować w programie ich działanie
*/

#include <iostream>

struct Osoba {
    std::string Imie;
    std::string Nazwisko;
    int PESEL[11];
    unsigned int Wzrost;
    Osoba(std::string imie = "", std::string nazwisko = "", std::string pesel = "00000000000", int wzrost = 0);
    void wypisz();
    void ZmienWzrost(unsigned int nowy_wzrost);
    void ZmienNazwisko(std::string nowe_nazwisko);
    bool czyKobieta();
    bool czyMezczyzna();
    int RokUrodzenia();
    int MiesiacUrodzenia();
    int DzienUrodzenia();
};

struct Grupa {
    Osoba osoby[30];
    int liczba_osob;
    Grupa();
    void DodajOsobe(Osoba o);
    void Wypisz();
    bool CzyJestMezczyzna();
    void UrodzoneWMiesiacu(int miesiac);
    float SredniWzrost();
    Osoba Najstarsza();
    Osoba Najmlodsza();
    void WypiszNazwiska();
};

Grupa NowaGrupaPrzedzial(Grupa grupa, int rok1, int rok2);
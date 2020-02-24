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


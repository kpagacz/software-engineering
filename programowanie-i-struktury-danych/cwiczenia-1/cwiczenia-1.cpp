# ifndef cwiczenia_1
# define cwiczenia_1
# include "cwiczenia-1.hpp"
# include <iostream>
# include <string>
# include <stdlib.h>
# include <stdexcept>

// Osoba
void Osoba::wypisz() {
    std::cout << "Imie: " << Imie << std::endl 
    << "Nazwisko: " << Nazwisko << std::endl;
    for (int i = 0; i < 11; i ++) {
        std::cout << PESEL[i];
    }
    std::cout << std::endl;
    std::cout << "Wzrost: " << Wzrost << std::endl;
};

Osoba::Osoba(std::string imie, std::string nazwisko, std::string pesel, int wzrost) {
        Imie = imie;
        Nazwisko = nazwisko;

        // poprawnosc PESEL-u - dlugosc
        if (pesel.length() != 11) {
            throw std::invalid_argument("Zla dlugosc PESELu.");
        }
        // poprawnosc PESELu - cyfry
        for (int i = 0; i < 11; i++) {
            if (isdigit(pesel[i])) {
                PESEL[i] = pesel[i] - '0';
            } else {
                throw std::invalid_argument("PESEL powininen miec tylko cyfry.");
            }
        }

        Wzrost = wzrost;
};

void Osoba::ZmienWzrost(unsigned int nowy_wzrost) {
    Wzrost = nowy_wzrost;
};

void Osoba::ZmienNazwisko(std::string nowe_nazwisko) {
    Nazwisko = nowe_nazwisko;
};

bool Osoba::czyKobieta() {
    return PESEL[9] % 2 == 0;
};

bool Osoba::czyMezczyzna() {
    return PESEL[9] % 2 == 1;
};

int Osoba::RokUrodzenia() {
    if (PESEL[2] * 10 + PESEL[3] > 20) {
        return 2000 + PESEL[0] * 10 + PESEL[1];
    } else {
        return 1990 + PESEL[0] * 10 + PESEL[1];
    }
}

int Osoba::MiesiacUrodzenia() {
    if (PESEL[2] * 10 + PESEL[3] > 20) {
        return (PESEL[2] - 2) * 10 + PESEL[3];
    } else {
        return (PESEL[2] * 10 + PESEL[3]);
    }
}

int Osoba::DzienUrodzenia() {
    return PESEL[4] * 10 + PESEL[5];
}


// Grupa
Grupa::Grupa() {
    liczba_osob = 0;
}

void Grupa::DodajOsobe(Osoba o) {
    osoby[liczba_osob] = o;
    liczba_osob++;
}

void Grupa::Wypisz() {
    for (int i = 0; i < liczba_osob; i++) {
        osoby[i].wypisz();
    }
}

bool Grupa::CzyJestMezczyzna() {
    bool sa_mezczyzni = false;
    for (int i = 0; i < liczba_osob; i++) {
        if (osoby[i].czyMezczyzna) {
            sa_mezczyzni = true;
            break;
        }
    }

    return sa_mezczyzni;
}

void Grupa::UrodzoneWMiesiacu(int miesiac) {
    for (int i = 0; i < liczba_osob; i++) {
        if (osoby[i].MiesiacUrodzenia == miesiac) {
            osoby[i].wypisz();
        }
    }
}

float Grupa::SredniWzrost() {
    int suma = 0;
    for (int i = 0; i < liczba_osob; i++) {
        suma += osoby[i].Wzrost;
    }
    return 1.0 * suma / liczba_osob;
}

Osoba Grupa::Najstarsza() {
    int najstarsza_indeks = 0;
    int najstarsza_rok = osoby[0].RokUrodzenia;

    for (int i = 0; i < liczba_osob; i++) {
        if (osoby[i].RokUrodzenia < najstarsza_rok) {
            najstarsza_rok = osoby[i].RokUrodzenia;
            najstarsza_indeks = i;
        }
    }

    return osoby[najstarsza_indeks];
}

Osoba Grupa::Najmlodsza() {
    int najmlodsza_indeks = 0;
    int najmlodsza_rok = osoby[0].RokUrodzenia;

    for (int i = 0; i < liczba_osob; i++) {
        if (osoby[i].RokUrodzenia > najmlodsza_rok) {
            najmlodsza_rok = osoby[i].RokUrodzenia;
            najmlodsza_indeks = i;
        }
    }

    return osoby[najmlodsza_indeks];
}

void Grupa::WypiszNazwiska() {
    for (int i = 0; i < liczba_osob; i++) {
        std::cout << osoby[i].Nazwisko << std::endl;
    }
}

Grupa NowaGrupaPrzedzial(Grupa grupa, int rok1, int rok2) {
    
}

# endif
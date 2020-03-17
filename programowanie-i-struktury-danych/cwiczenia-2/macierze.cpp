#ifndef _MACIERZE
#define _MACIERZE

#include "macierze.hpp"

#include <iostream>
#include <stdexcept>
#include <iomanip>

// konstruktory
Macierz::Macierz(int wiersze, int kolumny, float wypelnienie) {
    // sprawdzenie, czy wiersze i kolumny sa poprawnymi liczbami
    // 1. czy obie sa dodatnie
    if (wiersze > 0 && kolumny > 0) {
        wiersze_ = wiersze;
        kolumny_ = kolumny;
    } else {
        throw std::invalid_argument("Wiersze i kolumny musza byc wieksze od zera.");
    }

    // reprezentacja macierzy: tablica o  wiersze * kolumny elementach
    // inicjalizacja tablicy pelnej wartosci z wypelnienie
    macierz_ = new float[wiersze * kolumny];
    for (int i = 0; i < wiersze * kolumny; i++) {
        macierz_[i] = wypelnienie;
    }
}


// wypisywanie i pobieranie
void Macierz::PobierzMacierz() {
    std::cout << "Podaj pierwszy wiersz macierzy, a nastepnie kolejne. Macierz ma " << wiersze_ << " wierszy oraz " << kolumny_ << " kolumn." << std::endl;

    for (int i = 0; i < wiersze_; i++) {
        for (int j = 0; j < kolumny_; j++) {
            std::cin >> macierz_[i * kolumny_ + j];
        }
    }
}

void Macierz::WypiszMacierz() const {
    for (int i = 0; i < kolumny_ * 5; i++) {
        std::cout << "=";
    }
    std::cout << std::endl;
    for (int i = 0; i < wiersze_; i++) {
        for (int j = 0; j < kolumny_; j++) {
            std::cout << std::fixed << std::setprecision(2) << std::setw(5) << macierz_[i * kolumny_ + j];
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < kolumny_ * 5; i++) {
        std::cout << "=";
    }
    std::cout << std::endl;
}


// zwracanie elementu z konkretnej kolumny i wiersza
float Macierz::Element(int wiersz, int kolumna) const {
    return macierz_[kolumny_ * wiersz + kolumna];
}


// ustawienie elementu pod konkretnym indeksem
void Macierz::setElementAtIndex(int index, float value) {
    macierz_[index] = value;
}


// gettery
int Macierz::getKolumny() const {
    return kolumny_;
}

int Macierz::getWiersze() const {
    return wiersze_;
}


// algebra na macierzach
Macierz operator+(const Macierz& l, const Macierz& p) {
    if (l.getKolumny() != p.getKolumny() || l.getWiersze() != p.getWiersze()) {
        throw std::invalid_argument("Macierze musza miec takie same wymiary.");
    }

    Macierz suma_macierzy(l.getWiersze(), l.getKolumny());

    for (int i = 0; i < l.wiersze_; i++) {
        for (int j = 0; j < l.kolumny_; j++) {
            suma_macierzy.setElementAtIndex(i * l.kolumny_ + j, l.Element(i, j) + p.Element(i, j));
        }
    }

    return suma_macierzy;
}

Macierz operator-(const Macierz& l, const Macierz& p) {
    if (l.getKolumny() != p.getKolumny() || l.getWiersze() != p.getWiersze()) {
        throw std::invalid_argument("Macierze musza miec takie same wymiary.");
    }

    Macierz ujemna_p = -1 * p;
    return l + ujemna_p;
}

Macierz operator*(const Macierz& l, const Macierz& p) {
    if (l.getKolumny() != p.getWiersze()) {
        throw std::invalid_argument("Liczba kolumn lewej macierzy musi byc rowna licbie wierszy prawej macierzy.");
    }

    int wiersze = l.getWiersze();
    int kolumny = p.getKolumny();
    int ile_skladnikow_w_mnozeniu = l.getKolumny();

    Macierz wymnozona(wiersze, kolumny);

    
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            float suma = 0;
            for (int k = 0; k < ile_skladnikow_w_mnozeniu; k++) {
                suma += l.Element(i, k) * p.Element(k, j);
            }
            wymnozona.setElementAtIndex(i * kolumny + j, suma);
        }
    }

    return wymnozona;
}

Macierz operator*(const float& scalar, const Macierz& p) {
    int wiersze = p.getWiersze();
    int kolumny = p.getKolumny();

    Macierz wymnozona_macierz(wiersze, kolumny);
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            wymnozona_macierz.setElementAtIndex(i * kolumny + j, scalar * p.Element(i, j));
        }
    }
    return wymnozona_macierz;
}


// transpozycja
Macierz Macierz::Transponuj() const {
    int wiersze = getWiersze();
    int kolumny = getKolumny();

    Macierz transponowana(kolumny, wiersze);
    for (int i = 0; i < kolumny; i++) {
        for (int j = 0; j < wiersze; j++) {
            transponowana.setElementAtIndex(i * wiersze + j, Element(j, i));
        }
    }

    return transponowana;
}
#endif
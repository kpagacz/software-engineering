#ifndef __ULAMKI
#define __ULAMKI
#include <iostream>
#include <stdexcept>
#include "ulamki.hpp"

int NWD(int a, int b);
int* skracanie(int licznik1, int mianownik1, int licznik2, int mianownik2);

// skracanie bez obiektow
int* skracanie(int licznik1, int mianownik1, int licznik2, int mianownik2) {
    int nwd1 = NWD(licznik1, mianownik1);
    int nwd2 = NWD(licznik2, mianownik2);

    licznik1 = licznik1 / nwd1;
    mianownik1 = mianownik1 / nwd1;
    licznik2 = licznik2 / nwd2;
    mianownik2 = mianownik2 / nwd2;

    int* array_return = new int[4]{licznik1, mianownik1, licznik2, mianownik2};
    return array_return;
}

// konstruktor
Ulamek::Ulamek(int licznik, int mianownik) {
    if (mianownik == 0) {
        throw std::invalid_argument("mianownik nie moze byc 0.");
    }

    if (mianownik < 0) {
        licznik = licznik * (-1);
        mianownik = -1 * mianownik;
    }

    _licznik = licznik;
    _mianownik = mianownik;
}

// wypisywanie ulamka
void Ulamek::Wypisz() {
    std::cout << _licznik << " / " << _mianownik << std::endl;

}

// Skracanie ulamka
void Ulamek::SkrocUlamek() {
    int nwd = NWD(_licznik, _mianownik);
    _licznik = _licznik / nwd;
    _mianownik = _mianownik / nwd;
}

int NWD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return NWD(b, a % b);
    }
}

// Getters and setters
int Ulamek::getLicznik() {
    return _licznik;
}
int Ulamek::getMianownik() {
    return _mianownik;
}
void Ulamek::setLicznik(int licznik) {
    _licznik = licznik;
}
void Ulamek::setMianownik(int mianownik) {
    if (mianownik == 0) {
        throw std::invalid_argument("Mianownik nie moze byc 0.");
    }
    if (mianownik < 0) {
        mianownik = -1 * mianownik;
        _licznik = _licznik * (-1);
    }
    _mianownik = mianownik;
}

// Relational operators
bool operator<(const Ulamek& l, const Ulamek& r)  {
    int* new_fractions = skracanie(l._licznik, l._mianownik, r._licznik, r._mianownik);

    int licznik1 = new_fractions[0];
    int mianownik1 = new_fractions[1];
    int licznik2 = new_fractions[2];
    int mianownik2 = new_fractions[3];

    delete [] new_fractions;

    return licznik1 * mianownik2 < licznik2 * mianownik1;
}

bool operator>(const Ulamek& l, const Ulamek& r) {
    return r < l;
}
bool operator>=(const Ulamek& l, const Ulamek& r) {
    return !(l < r);
}
bool operator<=(const Ulamek& l, const Ulamek& r) {
    return !(r < l);
}

bool operator==(const Ulamek& l, const Ulamek& r) {
    int* new_fractions = skracanie(l._licznik, l._mianownik, r._licznik, r._mianownik);

    int licznik1 = new_fractions[0];
    int mianownik1 = new_fractions[1];
    int licznik2 = new_fractions[2];
    int mianownik2 = new_fractions[3];

    delete [] new_fractions;

    return (licznik1 == licznik2 && mianownik1 == mianownik2);
}

// binary operators
Ulamek operator+(const Ulamek& l, const Ulamek& r) {
    int* new_fractions = skracanie(l._licznik, l._mianownik, r._licznik, r._mianownik);

    int licznik1 = new_fractions[0];
    int mianownik1 = new_fractions[1];
    int licznik2 = new_fractions[2];
    int mianownik2 = new_fractions[3];

    delete [] new_fractions;

    int mianowniki_nwd = NWD(mianownik1, mianownik2);
    licznik1 = mianownik2 / mianowniki_nwd * licznik1;
    licznik2 = mianownik1 / mianowniki_nwd * licznik2;
    mianownik1 = mianownik2 / mianowniki_nwd * mianownik1;

    return Ulamek(licznik1 + licznik2, mianownik1);
}

Ulamek operator-(const Ulamek& l, const Ulamek& r) {
    Ulamek odwrotny(r._licznik, r._mianownik);
    return l + odwrotny;
}

Ulamek operator*(const Ulamek& l, const Ulamek& r) {
    int* new_fractions = skracanie(l._licznik, l._mianownik, r._licznik, r._mianownik);

    int licznik1 = new_fractions[0];
    int mianownik1 = new_fractions[1];
    int licznik2 = new_fractions[2];
    int mianownik2 = new_fractions[3];

    delete [] new_fractions;

    Ulamek ulamek_do_zwrocenia(licznik1 * licznik2, mianownik1 * mianownik2);
    ulamek_do_zwrocenia.SkrocUlamek();
    return ulamek_do_zwrocenia;
}

Ulamek operator/(const Ulamek& l, const Ulamek& r) {
    int* new_fractions = skracanie(l._licznik, l._mianownik, r._licznik, r._mianownik);

    int licznik1 = new_fractions[0];
    int mianownik1 = new_fractions[1];
    int licznik2 = new_fractions[3]; // zamiana z powodu dzielenia
    int mianownik2 = new_fractions[2]; // zamiana z powodu dzielenia

    delete [] new_fractions;

    Ulamek ulamek_do_zwrocenia(licznik1 * licznik2, mianownik1 * mianownik2);
    ulamek_do_zwrocenia.SkrocUlamek();
    return ulamek_do_zwrocenia;
}

#endif
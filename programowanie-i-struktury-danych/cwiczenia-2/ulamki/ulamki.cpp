#ifndef __ULAMKI
#define __ULAMKI
#include <iostream>
#include <stdexcept>
#include "ulamki.hpp"

int NWD(int a, int b);


Ulamek::Ulamek(int licznik, int mianownik) {
    if (mianownik == 0) {
        throw std::invalid_argument("mianownik nie moze byc 0.");
    }

    znak = true;
    if (licznik < 0) {
        znak = !znak;
        licznik = -1 * licznik;
    }

    if (mianownik < 0) {
        znak = !znak;
        mianownik = -1 * mianownik;
    }

    _licznik = licznik;
    _mianownik = mianownik;
}

void Ulamek::Wypisz() {
    if (znak) {
        std::cout << _licznik << " / " << _mianownik << std::endl;
    } else {
        std::cout << "- " << _licznik << " / " << _mianownik << std::endl;
    }
}

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

int Ulamek::getLicznik() {
    return _licznik;
}
int Ulamek::getMianownik() {
    return _mianownik;
}
void Ulamek::setLicznik(int licznik) {
    if (licznik < 0) {
        znak = !znak;
        licznik = -1 * licznik;
    }
    _licznik = licznik;
}
void Ulamek::setMianownik(int mianownik) {
    if (mianownik == 0) {
        throw std::invalid_argument("Mianownik nie moze byc 0.");
    }
    if (mianownik < 0) {
        znak = !znak;
        mianownik = -1 * mianownik;
    }
    _mianownik = mianownik;
}

bool operator<(const Ulamek& l, const Ulamek& r)  {
    
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
#endif
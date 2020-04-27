#include <iostream>
#include <stdexcept>
#include <string.h>

#include "1-plik.hpp"

// constructors, assignment, destructor
Katalog::Katalog(const Katalog& other) {
    Plik* it = other._head;

    while(it != nullptr) {
        Plik* creator = new Plik(it->nazwa, it->rozmiar, it->czy_ukryty);
        dodaj_plik(*creator);
        it = it->next_plik;
    }
}

Katalog::Katalog(Katalog&& other) {
    _head = other._head;

    other._head = nullptr;
}

Katalog& Katalog::operator=(const Katalog& other) {
    if(&other == this) {
        return *this;
    }
    
    empty();

    Plik* it = other._head;

    while(it != nullptr) {
        Plik* creator = new Plik(it->nazwa, it->rozmiar, it->czy_ukryty);
        dodaj_plik(*creator);
        it = it->next_plik;
    }

    return *this;
}

Katalog& Katalog::operator=(Katalog&& other) {
    empty();

    _head = other._head;

    other._head = nullptr;

    return *this;
}

Katalog::~Katalog() {
    Plik* it = _head;
    Plik* destroyer = nullptr;

    while(it != nullptr) {
        destroyer = it;
        it = it->next_plik;
        delete destroyer;
    }
}

// other
void Katalog::dodaj_plik(const Plik& new_plik) {
    Plik* creator = new Plik(new_plik.nazwa, new_plik.rozmiar, new_plik.czy_ukryty);
    
    // case: empty
    if(_head == nullptr) {
        _head = creator;
    } else {
    // case: not empty
        Plik* pred = nullptr;
        Plik* succ = _head;
        
        while(succ != nullptr) {
            int comparison = strcmp(succ->nazwa, creator->nazwa);
            // case: continue iterating
            if(comparison < 0) {
                pred = succ;
                succ = succ->next_plik;
            } else {
            // case: plik is already in katalog
                if(comparison == 0) {
                    throw std::invalid_argument("Plik already in Katalog.");
                } else {
            // case: insert plik before succ
                    creator->next_plik = succ;
                    if(pred == nullptr) {
                        _head = creator;
                    } else {
                        pred->next_plik = creator;
                    }
                    return;
                }
            }
        }

        // succ == nullptr here
        // insert at the end
        if(succ == nullptr) {
            pred->next_plik = creator;
        }
    }
}

void Katalog::kopiuj(const Katalog& other) {
    Plik* other_it = other._head;
    Plik* pred = nullptr;
    Plik* succ = _head;

    while(succ != nullptr && other_it != nullptr) {
        int comparison = strcmp(succ->nazwa, other_it->nazwa);

        if(comparison < 0) {
            pred = succ;
            succ = succ->next_plik;
            continue;
        }

        if(comparison == 0) {
            succ->rozmiar = other_it->rozmiar;
            succ->czy_ukryty = other_it->czy_ukryty;

            other_it = other_it->next_plik;
            pred = succ;
            succ = succ->next_plik;
            continue;
        }

        if(comparison > 0) {
            Plik* creator = new Plik(other_it->nazwa, other_it->rozmiar, other_it->czy_ukryty);
            if(pred == nullptr) {
                _head = creator;
            } else {
                pred->next_plik = creator;
            }

            creator->next_plik = succ;

            other_it = other_it->next_plik;
            pred = creator;
        }
    }

    // here either succ is nullptre or other_it is nullptr
    // if succ is and other is not, then fill this Katalog
    // with the rest of other Katalog
    if(succ == nullptr && other_it != nullptr) {
        while(other_it != nullptr){
            Plik* creator = new Plik(other_it->nazwa, other_it->rozmiar, other_it->czy_ukryty);
            pred->next_plik = creator;
            pred = creator;
            other_it = other_it->next_plik;
        }
    }
}

void Katalog::empty() {
    Plik* it = _head;
    Plik* destroyer = nullptr;

    while(it != nullptr) {
        destroyer = it;
        it = it->next_plik;
        delete destroyer;
    }

    _head = nullptr;
}

Katalog::Plik Katalog::get_plik(const char* nazwa, unsigned int rozmiar) {
    Plik plik = Plik(nazwa, rozmiar);
    return plik;
}

void Katalog::print() const {
    Plik* it = _head;

    std::cout << "Katalog: " << _head << std::endl;

    while(it != nullptr) {
        std::cout << it->nazwa << std::endl;
        it = it->next_plik;
    }
}
#ifndef SPORTOWCY
#define SPORTOWCY

#include "Sportowiec.h"
#include<vector>
#include<iostream>
class Sportowcy
{
private:
    std::vector<Sportowiec> sportowcy;

public:
    Sportowcy(std::vector<Sportowiec> _sportowcy = {}) : sportowcy(_sportowcy) {}
    Sportowcy(const Sportowcy&);        // copy constructor

    // getters
    std::vector<Sportowiec> getSportowcy() const;

    // modify sportowcy
    void dodajSportowca(const Sportowiec&);
    void modyfikujSportowca(unsigned int, const char*, const char*, double);
    void usunSportowca(const unsigned int& position);

    // operators
    Sportowcy& operator=(const Sportowcy&);     // assignment operator
    friend std::ostream& operator<<(std::ostream&, const Sportowcy&);
};

#endif //SPORTOWCY
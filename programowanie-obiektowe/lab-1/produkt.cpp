#include "produkt.h"
#include<iostream>


Produkt::~Produkt() {
    std::cout << "Usuwany: " << nazwa << endl;
}
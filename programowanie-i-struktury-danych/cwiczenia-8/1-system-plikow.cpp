#include <iostream>
#include "1-plik.hpp"

int main() {
    Katalog katalog1;

    auto plik1 = katalog1.get_plik("plikA", 2);
    auto plik2 = katalog1.get_plik("plikB", 3);
    auto plik3 = katalog1.get_plik("plikC", 4);

    katalog1.dodaj_plik(plik2);
    std::cout << "Katalog1: " << std::endl;
    katalog1.print();

    katalog1.dodaj_plik(plik3);
    std::cout << "Katalog1: " << std::endl;
    katalog1.print();

    katalog1.dodaj_plik(plik1);
    std::cout << "Katalog1: " << std::endl;
    katalog1.print();

    try
    {
        std::cout << "Adding the same file twice:" << std::endl;
        katalog1.dodaj_plik(plik1);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error caught:" << e.what() << std::endl;
    }
    
    Katalog katalog2;
    auto plik4 = katalog1.get_plik("plikB", 5);
    katalog2.dodaj_plik(plik4);
    std::cout << "Katalog2: " << std::endl;
    katalog2.print();
    katalog2.kopiuj(katalog1);
    std::cout << "Katalog2.kopiuj(katalog1): " << std::endl;
    katalog2.print();


    return 0;
}
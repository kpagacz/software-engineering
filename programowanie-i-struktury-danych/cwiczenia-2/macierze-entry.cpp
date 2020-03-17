#include "macierze.hpp"

#include <iostream>

int main() {
    // testowanie domyslnej macierzy
    Macierz m1(1, 1);
    m1.WypiszMacierz();

    try
    {
        Macierz m2(-1, 1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // testowanie pobierania
    m1.PobierzMacierz();
    m1.WypiszMacierz();
    
    // testowania zwracania wartosci
    std::cout << "Testowanie Macierz::Element()" << std::endl;
    std::cout << "Wartosc elementu [0, 0]: "<< m1.Element(0,0) << std::endl;

    // testowanie dodawania macierzy
    std::cout << "Testowanie dodawania macierzy." << std::endl;
    Macierz skladnik1(2, 3, 1);
    Macierz skladnik2(2, 3, 2);
    Macierz suma1 = skladnik1 + skladnik2;
    suma1.WypiszMacierz();

    // testowanie Macierz::setElementAtIndex()
    std::cout << "Testowanie ustawiania elementu pod indeksem w tablicy." << std::endl;
    skladnik1.setElementAtIndex(4, 5);
    skladnik1.WypiszMacierz();    

    // testowanie mnozenia przez skalar
    Macierz iloczyn1 = 7.0 * skladnik1;
    iloczyn1.WypiszMacierz();

    // testowanie odejmowania macierzy
    std::cout << "Testowanie odejmowania macierzy." << std::endl;
    Macierz roznica1 = skladnik1 - skladnik2;
    roznica1.WypiszMacierz();


    // testowania transponowa
    std::cout << "Testowanie transponowania." << std::endl;
    Macierz transponowana(4, 2, 1);
    transponowana.setElementAtIndex(4, 3);
    std::cout << "Macierz do transpozycji: " << std::endl;
    transponowana.WypiszMacierz();
    Macierz po_transpozycji = transponowana.Transponuj();
    po_transpozycji.WypiszMacierz();

    // testowanie mnozenia dwoch macierzy
    std::cout << "Testowanie mnozenia dwoch macierzy." << std::endl;
    Macierz iloczyn2 = po_transpozycji * transponowana;
    iloczyn2.WypiszMacierz();

    return 0;
}
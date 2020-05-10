#include <iostream>
#include "0-sznur.hpp"

int main() {
    Sznur sznur1;

    sznur1.push_back(7);
    sznur1.push_back(9);
    sznur1.push_back(10);
    std::cout << sznur1;

    std::cout << "Sznur po odwroceniu N=2:" << std::endl;
    sznur1.Odwroc(2);
    std::cout << sznur1;

    std::cout << "Sznur po odwroceniu N=3" << std::endl;
    sznur1.Odwroc(3);
    std::cout << sznur1;


    sznur1.push_back(9);
    std::cout << sznur1;

    std::cout << "Sznur po UsunFragmenty(2)" << std::endl;
    sznur1.UsunFragmenty(2);
    std::cout << sznur1;
    
    std::cout << "Sznur po usunfragmenty(1)" << std::endl;
    sznur1.UsunFragmenty(1);
    std::cout << sznur1;

    sznur1.push_back(10);
    sznur1.push_back(10);
    sznur1.push_back(7);
    std::cout << sznur1;
    std::cout << "Sznur1 po usubfragmenty(2):" << std::endl;
    sznur1.UsunFragmenty(2);
    std::cout << sznur1;

    sznur1.push_back(1);
    sznur1.push_back(1);
    sznur1.push_back(2);
    sznur1.push_back(3);
    sznur1.push_back(4);
    sznur1.push_back(5);
    sznur1.push_back(6);
    sznur1.push_back(7);

    std::cout << sznur1;
    std::cout << "Sznur1 after usunzpar(4)" << std::endl;
    sznur1.usunZPar(4);
    std::cout << sznur1;

    sznur1.push_back(4);
    std::cout << sznur1;
    std::cout << "Sznur1 after przestawparzyste: " << std::endl;
    sznur1.przestawParzyste();
    std::cout << sznur1;

    Sznur sznur2;
    sznur2.push_back(11);
    sznur2.push_back(12);
    sznur2.push_back(13);
    sznur2.push_back(14);
    std::cout << sznur2;

    std::cout << "Sznury after sznur1.Przegrupuj(sznur2);" << std::endl;
    sznur1.Przegrupuj(sznur2);
    std::cout << sznur1 << sznur2;
    return 0;
}
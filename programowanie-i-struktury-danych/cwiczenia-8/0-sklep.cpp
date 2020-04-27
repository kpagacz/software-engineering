#include <iostream>
#include "spis-towarow.hpp"

int main() {
    Spis_towarow spis1;
    auto towar1 = spis1.zrob_towar(2, 1);

    spis1.wstaw(towar1);
    spis1.print();

    auto towar2 = spis1.zrob_towar(3, 1);
    spis1.wstaw(towar2);
    spis1.print();    

    auto towar3 = spis1.zrob_towar(5, 1);
    spis1.wstaw(towar3);
    spis1.print();  

    auto towar4 = spis1.zrob_towar(4, 1);
    spis1.wstaw(towar4);
    spis1.print();  

    auto towar5 = spis1.zrob_towar(1, 1);
    spis1.wstaw(towar5);
    spis1.print();  

    // copy constructor
    Spis_towarow spis2(spis1);
    spis2.print();

    // wstaw_rozno
    auto towar6 = spis2.zrob_towar(1, 3);
    spis2.wstaw_roznowartosciowo(towar6);
    spis2.print();

    // odejmowanie
    std::cout << "Testowanie odejmowania" << std::endl;
    Spis_towarow spis3;
    spis3.wstaw(towar3);
    spis3.wstaw(towar2);
    spis3.wstaw(towar2);
    std::cout << "Spis3: " << std::endl;
    spis3.print();

    std::cout << "Spis2: " << std::endl;
    spis2.print();

    std::cout << "Spis2 - Spis3" << std::endl;
    spis2.odejmij_ze_spisu(spis3);
    spis2.print();

    Spis_towarow spis4;
    spis4.wstaw(towar3);
    std::cout << "Spis4: " << std::endl;
    spis4.print();
    std::cout << "Spis2 - Spis4" << std::endl;
    spis2.odejmij_ze_spisu(spis4);
    spis2.print();

    Spis_towarow spis5;
    spis5.wstaw(towar6);
    spis5.wstaw(towar6);
    std::cout << "Spis5: " << std::endl;
    spis5.print();
    std::cout << "Spis2 - Spis5: " << std::endl;
    spis2.odejmij_ze_spisu(spis5);
    spis2.print();

    Spis_towarow spis6;
    spis6.wstaw(towar1);
    spis6.wstaw(towar1);
    spis6.wstaw(towar1);
    spis6.wstaw(towar2);
    spis6.wstaw(towar2);

    std::cout << "Spis6: " << std::endl;
    spis6.print();
    spis6.skompresuj();
    std::cout << "Spis6 po kompresji:" << std::endl;
    spis6.print();

    return 0;
}
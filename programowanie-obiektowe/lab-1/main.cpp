#include "produkt.h"

int main() {
    Produkt p1;
    Produkt p2("bulka");
    Produkt p3("chleb", 4.5);
    Produkt p4("tosty", 6.0, true);
    
    p4.setName("nowy");
    std::cout << p4.getName();

    return 0;
}
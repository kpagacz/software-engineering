#include <iostream>
#include "Planet.h"
#include "Plaszczak.h"

int main()
{
    Plaszczak Teodor('@', 8, 8);
    Plaszczak Nieznany;
    Planet Rect001("Rect001", 10, 10, &Teodor);
    std::cout << Teodor << "\n" << Nieznany << "\n";

    std::cout << Rect001;
    return 0;
}

// Napisać program wypisujący tabelkę postaci
//
//  p      q      p and q    p or q    not p
// true   true      ...       ....      ...
// true   false     ...       ....      ... 
// false  true      ...       ....      ...
// false  false     ...       ....      ...
//
// (p i q mają być zmiennymi) 

#include <iostream>
#include <iomanip>

int main() {
    // input
    const int width = 10;

    // first line
    std::cout << std::left << std::setw(width) << " p"; 
    std::cout << std::left << std::setw(width) << " q";
    std::cout << std::left << std::setw(width) << " p and q";
    std::cout << std::left << std::setw(width) << " p or q";
    std::cout << std::left << std::setw(width) << " not p";
    std::cout << std::endl;

    // next lines
    for (bool p: {true, false}) {
        for (bool q: {true, false}) {
            std::cout << std::left << std::setw(width) << std::boolalpha << p ;
            std::cout << std::left << std::setw(width) << std::boolalpha << q;
            std::cout << std::left << std::setw(width) << std::boolalpha << p && q;
            std::cout << std::left << std::setw(width) << std::boolalpha << p || q;
            std::cout << std::left << std::setw(width) << std::boolalpha << !p;
            std::cout << std::endl;
        }
    }
    return 0;
}
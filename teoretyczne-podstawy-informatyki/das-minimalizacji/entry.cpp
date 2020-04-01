#include "das.hpp"
#include <iostream>


int main() {
    DAS das;
    das.inputDAS();
    std::cout << "YOUR DAS" << std::endl;
    das.print();

    DAS minimized_das = das.minimizeDAS();

    std::cout << "MINIMIZED DAS" << std::endl;
    minimized_das.print();
    return 0;
}
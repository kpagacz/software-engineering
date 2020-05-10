#include <iostream>
#include "1-lista.hpp"

int main() {
    Lista_studentow lista1;

    Student stud1(1, 3.0);
    Student stud2(2, 3.1);
    Student stud3(4, 3.2);
    Student stud4(3, 3.3);
    lista1.push(stud1);
    lista1.push(stud2);

    std::cout << lista1;

    try{
        std::cout << "Pushing duplicate id. Should throw" << std::endl;
        lista1.push(stud2);
    } catch(std::exception& e) {
        std::cout << "Exception: " << e.what();
    }

    lista1.push(stud3);
    lista1.push(stud4);

    std::cout << lista1;

    lista1.ordered_output(4);
    std::cout << lista1;


    lista1.delete_failing(3.2);
    std::cout << lista1;
    return 0;
}
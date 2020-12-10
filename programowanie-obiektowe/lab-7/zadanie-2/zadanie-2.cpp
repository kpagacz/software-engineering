#include <iostream>
#include "zoo.h"
#include<stdlib.h>

int main() {
    srand(0);

    std::cout << "Podaj rozmiar: ";
    int size;
    std::cin >> size;
    Zwierze** gromada = new Zwierze*[size];

    for(int i = 0; i < size; i++) {
        int random = rand() % 3;
        switch(random){
            case 0:
                gromada[i] = new Pies;
                break;
            case 1:
                gromada[i] = new Kot;
                break;
            case 2:
                gromada[i] = new Swinia;
                break;
        }
    }

    for(int i = 0; i < size; i++) {
        gromada[i]->dajGlos();
        delete gromada[i];
    }

    delete [] gromada;
    return 0;
}
// lab-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include"Sportowiec.h"
#include"Sportowcy.h"


int main()
{
    Sportowiec s1;
    Sportowiec s2("nazwisko1", "sport1", 50);

    std::cout << s1;
    std::cout << s2;

    Sportowiec s3(s2);
    std::cout << s3;

    s1 = s3;
    std::cout << s1;

    std::cout << s1.getIle() << "\n";

    // Prosty program
    Sportowcy sportowcy1;

    char c = 'c';

    while (c != 'e') {
        std::cout << "Co chcesz zrobic?\n"
            << "1 - dodaj sportowca\n"
            << "2 - modyfikuj sportowca\n"
            << "3 - usun sportowca\n"
            << "4 - drukuj sportowcow\n"
            << "e - wyjdz z programu\n";

        std::cin >> c;
        std::string imie = "", sport = "";
        double waga;
        int numer;
        Sportowiec s1;

        switch (c) {
        case '1':
            std::cout << "Podaj imie, sport oraz wage: ";
            std::cin >> imie >> sport >> waga;

            s1.setNazwisko(imie.data());
            s1.setSport(sport.data());
            s1.setWaga(waga);
            sportowcy1.dodajSportowca(s1);

            continue;
        case '2':
            std::cout << "Podaj numer sportowca do modyfikacji: ";
            std::cin >> numer;

            std::cout << "Podaj imie, sport oraz wage: ";
            std::cin >> imie >> sport >> waga;

            sportowcy1.modyfikujSportowca(numer, imie.data(), sport.data(), waga);

            continue;
        case '3':
            std::cout << "Podaj numer sportowca do usuniecia: ";
            std::cin >> numer;
            sportowcy1.usunSportowca(numer);

            continue;
        case '4':
            std::cout << sportowcy1;
            continue;
        case 'e':
            break;

        default:
            continue;
        }
    }

    return 0;
}

// lab-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Sportowiec.h"
#include<vector>

struct Sportowcy {
    std::vector<Sportowiec> sportowcy;
    Sportowcy(std::vector<Sportowiec> _sportowcy) : sportowcy(_sportowcy) {}
};

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

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

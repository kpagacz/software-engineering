// Napisać program umożliwiający przeliczanie między różnymi jednostkami 
// miary (np. cale - cm, jardy - metry, sążnie na metry itd. Zamianę 
// zrealizować za pomocą funkcji. Program powinien umożliwisć wielokrotne 
// podawanie przeliczanej wartości i wybieranie przeliczanych jednostek. 

#include <iostream>

float inch_to_cm(float a);
float cm_to_inch(float a);
float yard_to_m(float a);
float m_to_yard(float a);
float fathom_to_m(float a);
float m_to_fathom(float a);

int main() {
    char choice;
    float distance;

    while(true) {
        std::cout << "Distance units calculator:" << std::endl;
        std::cout << "a - inch to centimeters." << std::endl <<
        "b - centimeters to inch." << std::endl <<
        "c - yards to meters" << std::endl <<
        "d - meters to yards" << std::endl <<
        "e - fathom to meters" << std::endl <<
        "f - meters to fathom" << std::endl <<
        "z - end program" << std::endl;
        std::cin >> choice;

        switch(choice){
            case 'a' :
                std::cout << "Input inches: ";
                std::cin >> distance;
                std::cout << "Centimeters: " << inch_to_cm(distance) << std::endl;
                continue;
            case 'b' :
                std::cout << "Input centimeters: ";
                std::cin >> distance;
                std::cout << "Centimeters: " << cm_to_inch(distance) << std::endl;
                continue;
            case 'c' :
                std::cout << "Input yards: ";
                std::cin >> distance;
                std::cout << "Centimeters: " << yard_to_m(distance) << std::endl;
                continue;
            case 'd' :
                std::cout << "Input meters: ";
                std::cin >> distance;
                std::cout << "Centimeters: " << m_to_yard(distance) << std::endl;
                continue;
            case 'e' :
                std::cout << "Input fathoms: ";
                std::cin >> distance;
                std::cout << "Centimeters: " << fathom_to_m(distance) << std::endl;
                continue;
            case 'f' :
                std::cout << "Input meters: ";
                std::cin >> distance;
                std::cout << "Centimeters: " << m_to_fathom(distance) << std::endl;
                continue;
            case 'z' :
                std::cout << "End." << std::endl;
                return 0;
        }

    }

    return 0;
}


float inch_to_cm(float a) {
    return 2.54 * a;
}

float cm_to_inch(float a) {
    return a / 2.54;
}

float yard_to_m(float a) {
    return a * 0.9144;
}

float m_to_yard(float a) {
    return a / 0.9144;
}

float fathom_to_m(float a) {
    return a * 1.8288;
}

float m_to_fathom(float a) {
    return a / 1.8288;
}
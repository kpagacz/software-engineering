#define _USE_MATH_DEFINES
#undef __STRICT_ANSI__
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    // radius and height - input
    std::cout << "Please input two integeres - radius of the basis and height of the cylinder.\n";
    int radius, height;
    float volume, area;

    // while(std::cin >> radius >> height) {
    //     if (radius <= 0 || height <= 0) {
    //         continue;
    //     }
    // }

    // forcing the correct input
    do {
        std::cin >> radius >> height;
    } while (radius <= 0 || height <= 0);

    // area or volume - input
    std::cout << "Please choose the area (a) or volume (v) to calculate.\n";
    char choice;
    std::cin >> choice;

    // calculations
    switch(choice){
        case 'a':
            area = 2 * M_PI * radius * height + 2 * M_PI * radius * radius;
            std::cout << std::fixed << std::setprecision(2) << "Area of a cylinder with radius " << radius << " and height " << height << " is: " << area;
            break;
        case 'v':
            volume = M_PI * radius * radius * height;
            std::cout << std::fixed << std::setprecision(2) << "Volume of a cylinder with radius " << radius << " and height " << height << " is: " << volume;
            break;
        default:
            std::cout << "Please input a or v as a choice.\n";
    }
    return 0;
}
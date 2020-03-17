#include "geometria.hpp"
#include <iostream>

int main() {
    // setters and getters testing
    
    // testing default constructors
    Punkt point1;
    Prosta line1;

    std::cout << "Testing default constructors and getters for Punkt: ";
    if(point1.GetX() == 0 && point1.GetY() == 0) {
        std::cout << "success." << std::endl;
    } else {
        std::cout << "failure." << std::endl;
        point1.Print();
    }

    std::cout << "Testing default constructors and getters for Prosta: ";
    if(line1.GetA() == 1 && line1.GetB() == 0) {
        std::cout << "success." << std::endl;
    } else {
        std::cout << "failure." << std::endl;
        line1.Print();
    }

    // testing printing methods
    std::cout << "Testing printing of Punkt and Prosta" << std::endl;
    point1.Print();
    line1.Print();

    // testing isPointOnLine()
    Punkt point_on_line2(3, 10);
    Prosta line2(2, 4);
    std::cout << "Testing isPointOnLine(): ";
    if (isPointOnLine(point_on_line2, line2)) {
        std::cout << "passed" << std::endl;
    } else {
        std::cout << "failed" << std::endl;
        point_on_line2.Print();
        line2.Print();
    }

    // testing constructor of Prosta from two Punkty
    Punkt point2_on_line2(2, 8);
    Prosta line3(point_on_line2, point2_on_line2);
    std::cout << "Testing initializing Prosta from two Punkt: ";
    if (line2.GetA() == line3.GetA() && line2.GetB() == line3.GetB()) {
        std::cout << "passed" << std::endl;
    } else {
        std::cout << "failed" << std::endl;
    }

    std::cout << "Testing throwing an exception for two Points that do not lie on a single line: ";
    bool exception_thrown = false;
    Punkt point3(2, 4);
    Punkt point4(4, 5);
    try {
        Prosta should_throw(point3, point4);
    } catch (std::exception& e) {
        std::cout << "passed" << std::endl;
        exception_thrown = true;
    }
    // exception not thrown - test failed
    if (!exception_thrown) {
        std::cout << "failed" << std::endl;
        Prosta should_throw(point3, point4);
        should_throw.Print();
    }
    return 0;
}
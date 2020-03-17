#ifndef _GEOMETRIA
#define _GEOMETRIA
#include "geometria.hpp"
#include <iostream>
#include <stdexcept>

// PUNKT
// constructors for Punkt
Punkt::Punkt(int x, int y) {
    _x = x;
    _y = y;
}

// setters and getters for Punkt
int Punkt::GetX() const{
    return _x;
}
int Punkt::GetY() const{
    return _y;
}
void Punkt::SetX(int x) {
    _x = x;
}
void Punkt::SetY(int y) {
    _y = y;
} 

// printing
void Punkt::Print() const{
    std::cout << "X=" << _x << " Y=" << _y << std::endl;
}

// PROSTA
// constructors for Prosta
Prosta::Prosta(int a, int b) {
    _a = a;
    _b = b;
}

Prosta::Prosta(const Punkt& point1, const Punkt& point2) {
    int x1 = point1.GetX();
    int y1 = point1.GetY();
    int x2 = point2.GetX();
    int y2 = point2.GetY();

    if (x1 == x2) {
        throw std::invalid_argument("There is no function passing through the provided 2 points.");
    }

    _a = (y2 - y1) / (x2 - x1);
    _b = y1 - x1 * (y2 - y1) / (x2 - x1);

    // check if the points lie on the line
    if (_a * x1 + _b != y1 || _a * x2 + _b != y2) {
        throw std::invalid_argument("There is no line with int coefficients passing through the provided 2 points.");
    }
}

// setters and getter for Prosta
int Prosta::GetA() const {
    return _a;
}

int Prosta::GetB() const {
    return _b;
}

void Prosta::SetA(int a) {
    _a = a;
}

void Prosta::SetB(int b) {
    _b = b;
}

// printing
void Prosta::Print() const {
    std::cout << "f(x) = " << _a << "*x + " << _b << std::endl;
}


// global functions
bool isPointOnLine(const Punkt& point, const Prosta& line) {
    return point.GetY() == line.GetA() * point.GetX() + line.GetB();
}

#endif
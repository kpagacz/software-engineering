#ifndef PLANET_H
#define PLANET_H

#include "Plaszczak.h"
#include<string>

class Planet
{
private:
	std::string name;
	int width, height;
	Plaszczak* p; 
public:
	Planet(std::string n, int w, int h, Plaszczak* p = nullptr) : name(n), width(w), height(h), p(p) {};
	virtual ~Planet();

	// print
	friend std::ostream& operator<<(std::ostream& out, const Planet& planet);

	// ruchy
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
};

#endif // PLANET_H
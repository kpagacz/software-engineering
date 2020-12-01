#ifndef PLANET_H
#define PLANET_H

#include "Plaszczak.h"
#include<string>
#include<vector>

class Planet
{
private:
	std::string name;
	int width, height;
	std::vector<Plaszczak> animals;
public:
	Planet(std::string n, int w, int h) : name(n), width(w), height(h), animals({}) {};
	virtual ~Planet();

	// print
	friend std::ostream& operator<<(std::ostream& out, const Planet& planet);

	// ruchy
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

	// add animal
	void addPlaszczak(const Plaszczak& p);
};

#endif // PLANET_H
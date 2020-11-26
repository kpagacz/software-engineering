#include "Planet.h"

Planet::~Planet()
{
	delete p;
}

void Planet::moveUp()
{
	--(p->gety());
}

void Planet::moveDown()
{
	(p->gety())++;
}

void Planet::moveRight()
{
	(p->getx())++;
}

void Planet::moveLeft()
{
	(p->getx())--;
}

std::ostream& operator<<(std::ostream& out, const Planet& planet)
{
	for (int j = 0; j < planet.height; ++j) {
		for (int i = 0; i < planet.width; ++i) {
			if (i == 0 || j == 0 || j == planet.width - 1 || i == planet.height - 1) {
				out << 'x';
			}
			else if (i == planet.p->getx() && j == planet.p->gety()) {
				out << *(planet.p);
			}
			else {
				out << ' ';
			}
		}
		out << "\n";
	}
	return out;
}

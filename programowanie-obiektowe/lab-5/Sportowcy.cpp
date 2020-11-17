#include "Sportowcy.h"
#include<iostream>
#include<vector>

std::vector<Sportowiec> Sportowcy::getSportowcy() const
{
	return sportowcy;
}

void Sportowcy::dodajSportowca(const Sportowiec& _el)
{
	sportowcy.push_back(_el);
}

void Sportowcy::modyfikujSportowca(unsigned int position, const char* nazwisko, const char* sport, double waga)
{
	sportowcy.at(position).setNazwisko(nazwisko);
	sportowcy.at(position).setSport(sport);
	sportowcy.at(position).setWaga(waga);
}

void Sportowcy::usunSportowca(const unsigned int &position)
{
	std::vector<Sportowiec>::iterator it = std::next(sportowcy.begin(), position);
	sportowcy.erase(it);
}

Sportowcy& Sportowcy::operator=(const Sportowcy& other)
{
	if (this == &other) {
		return *this;
	}

	sportowcy = other.getSportowcy();
	return *this;
}

Sportowcy::Sportowcy(const Sportowcy& other)
{
	sportowcy = other.getSportowcy();
}

std::ostream& operator<<(std::ostream& out, const Sportowcy& sportowcy)
{
	out << "==============================\n";

	int i = 0;
	for (auto it = sportowcy.sportowcy.begin(); it != sportowcy.sportowcy.end(); it++, i++) {
		out << "SPORTOWIEC numer: " << i << "\n";
		out << *it;
		out << "===============================\n";
	}

	return out;
}

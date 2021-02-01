#include "Ksiazka.h"

Ksiazka::Ksiazka(const Ksiazka& other)
{
	name = other.name;
}

std::string Ksiazka::get_name() const
{
	return name;
}

void Fikcja::print(std::ostream& out) const
{
	out << "Tytul: " << get_name() << " Gatunek: Fikcja\n";
}

Ksiazka* Fikcja::clone() const
{
	Ksiazka* clone = new Fikcja(*this);
	return clone;
}

void Podroze::print(std::ostream& out) const
{
	out << "Tytul: " << get_name() << " Gatunek: Podroze\n";
}

Ksiazka* Podroze::clone() const
{
	Ksiazka* clone = new Podroze(*this);
	return clone;
}

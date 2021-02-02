#include "Produkt.h"

int& Produkt::get_cena()
{
	return cena;
}

std::string& Produkt::get_name()
{
	return nazwa;
}

void Jedzenie::print(std::ostream& out)
{
	out << "Rodzaj produktu: Jedzenie. Nazwa Produktu: " << get_name() << " Cena produktu: " << get_cena() << "\n";
}

Produkt* Jedzenie::clone() const
{
	Produkt* kopia = new Jedzenie(*this);
	return kopia;
}

void Chemia::print(std::ostream& out)
{
	out << "Rodzaj produktu: Chemia. Nazwa Produktu: " << get_name() << " Cena produktu: " << get_cena() << "\n";
}

Produkt* Chemia::clone() const
{
	Produkt* klon = new Chemia(*this);
	return klon;
}

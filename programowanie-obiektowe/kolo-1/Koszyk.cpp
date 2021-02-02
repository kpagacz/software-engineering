#include "Koszyk.h"

Koszyk::~Koszyk()
{
	for (auto produkt : produkty)
		delete produkt;
}

Koszyk::Koszyk(const Koszyk& other)
{
	for (auto nowy_produkt : other.produkty) produkty.push_back(nowy_produkt->clone());
}

Koszyk& Koszyk::operator+(Produkt* nowy_produkt)
{
	produkty.push_back(nowy_produkt);
	return *this;
}

void Koszyk::print(std::ostream& out) const
{
	std::cout << "PARAGON:\n";
	for (auto produkt : produkty) produkt->print(out);
}

void Koszyk::zwroc(const std::string& do_zwrocenia)
{
	auto found = std::find_if(produkty.begin(), produkty.end(), [do_zwrocenia](auto p) { return p->get_name() == do_zwrocenia; });
	if (found != produkty.end()) produkty.erase(found);
}

void Koszyk::zwroc(const unsigned int& position)
{
	if (position < produkty.size())
		produkty.erase(produkty.begin() + position);
}

Koszyk Koszyk::wybraneProdukty(int min_cena, int max_cena)
{
	Koszyk nowy_koszyk;
	for (auto produkt : produkty) {
		if (produkt->get_cena() >= min_cena && produkt->get_cena() <= max_cena)
			nowy_koszyk.produkty.push_back(produkt->clone());
	}
	return nowy_koszyk;
}

std::ostream& operator<<(std::ostream& out, const Koszyk& kosz)
{
	kosz.print(out);
	return out;
}

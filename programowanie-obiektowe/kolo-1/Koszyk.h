#ifndef KOSZYK__
#define KOSZYK__

#include <vector>
#include "Produkt.h"

class Koszyk
{
public:
	Koszyk() = default;
	~Koszyk();
	Koszyk(const Koszyk& other);

	// operator overload
	Koszyk& operator+(Produkt* nowy_produkt);
	friend std::ostream& operator<<(std::ostream& out, const Koszyk& kosz);
	
	// other methods
	void print(std::ostream& out) const;
	// zwroc usuwa najwczesniej dodany produkt o nazwie do_zwrocenia,
	// gdy jest wiecej produktow o nazwie do_zwrocenia w koszyku
	void zwroc(const std::string& do_zwrocenia);
	void zwroc(const unsigned int& position);
	Koszyk wybraneProdukty(int min_cena, int max_cena);
private:
	std::vector<Produkt*> produkty;
};

#endif // KOSZYK__

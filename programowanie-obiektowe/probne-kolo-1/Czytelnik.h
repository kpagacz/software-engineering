#ifndef CZYTELNIK__
#define CZYTELNIK__

#include <iostream>
#include <vector>

#include "Ksiazka.h"

class Czytelnik
{
public:
	// constructors, destructors
	Czytelnik() = default;
	Czytelnik(const Czytelnik& other);
	~Czytelnik();

	// operator overload
	Czytelnik& operator+(Ksiazka*);
	Ksiazka& operator[](int i);

	// other methods
	void print(std::ostream&);
	void zwroc(const std::string& _name);
	Czytelnik wybraneKsiazki(Gatunki gatunek) const;
private:
	std::vector<Ksiazka*> wypozyczone;
};

#endif // CZYTELNIK__


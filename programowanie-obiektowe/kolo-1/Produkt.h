#ifndef PRODUKT__
#define PRODUKT__

#include <string>
#include <iostream>

class Produkt
{
public:
	Produkt(std::string _nazwa = "", int _cena = 0) : cena(_cena), nazwa(_nazwa) {}
	virtual ~Produkt() = default;
	int& get_cena();
	std::string& get_name();
	virtual void print(std::ostream&) = 0;
	virtual Produkt* clone() const = 0;
private:
	int cena;
	std::string nazwa;
};

class Jedzenie : virtual public Produkt {
public:
	Jedzenie(std::string _nazwa = "", int _cena = 0, bool _gluten_free = false) : Produkt(_nazwa, _cena), bezglutenowe(_gluten_free) {};
	~Jedzenie() = default;
	void print(std::ostream& out);
	Produkt* clone() const;
private:
	bool bezglutenowe;
};

class Chemia : virtual public Produkt {
public:
	Chemia(std::string _nazwa = "", int _cena = 0, bool _do_podlog = false) : Produkt(_nazwa, _cena), do_podlog(_do_podlog) {}
	~Chemia() = default;
	void print(std::ostream& out);
	Produkt* clone() const;
private:
	bool do_podlog;
};

#endif // PRODUKT__
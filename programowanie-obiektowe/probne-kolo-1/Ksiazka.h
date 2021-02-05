#ifndef KSIAZKA__
#define KSIAZKA__

#include <string>
#include <iostream>

enum class Gatunki {
	Podroze,
	Fikcja
};

class Ksiazka
{
public:
	Ksiazka(std::string _name = "") : name(_name) {}
	virtual ~Ksiazka() = default;
	Ksiazka(const Ksiazka& other);

	std::string get_name() const;
	virtual void print(std::ostream&) const = 0;
	virtual Ksiazka* clone() const = 0;
private:
	std::string name;
};

class Fikcja : public virtual Ksiazka {
public:
	Fikcja(std::string _name = "") : Ksiazka(_name) {}
	~Fikcja() = default;
	void print(std::ostream&) const;
	Ksiazka* clone() const;
};

class Podroze : public virtual Ksiazka {
public:
	Podroze(std::string _name = "") : Ksiazka(_name) {}
	~Podroze() = default;
	void print(std::ostream&) const;
	Ksiazka* clone() const;
};



#endif // KSIAZKA__
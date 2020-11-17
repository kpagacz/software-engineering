#ifndef SPORTOWIEC
#define SPORTOWIEC

#include<iostream>
class Sportowiec
{
private:
	static int ile;
	char* nazwisko, * sport;
	double waga;
public:
	Sportowiec();
	Sportowiec(const char*, const char*, const double);
	~Sportowiec();
	Sportowiec(const Sportowiec&);
	Sportowiec& operator=(const Sportowiec&);
	static int getIle();
	friend std::ostream& operator<<(std::ostream& out, const Sportowiec&);

	// setters
	void setWaga(const int&);
	void setNazwisko(const char*);
	void setSport(const char*);

};

#endif // SPORTOWIEC

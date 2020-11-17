#define _CRT_SECURE_NO_WARNINGS
#include "Sportowiec.h"

#include<iostream>
#include<string.h>

int Sportowiec::ile = 0;

Sportowiec::Sportowiec()
{
	nazwisko = new char[5];
	sport = new char[5];
	strncpy(nazwisko, "brak", 5);
	strncpy(sport, "brak", 5);
	waga = 0;
	ile++;
}

Sportowiec::Sportowiec(const char* _nazwisko, const char* _sport, const double _waga)
{
	nazwisko = new char[strlen(_nazwisko) + 1];
	sport = new char[strlen(_sport) + 1];
	strcpy(sport, _sport);
	strcpy(nazwisko, _nazwisko);

	ile++;
	waga = _waga;
}

Sportowiec::~Sportowiec()
{
	delete[] nazwisko;
	delete[] sport;
	ile--;
}

Sportowiec::Sportowiec(const Sportowiec& other)
{
	nazwisko = new char[strlen(other.nazwisko) + 1];
	sport = new char[strlen(other.sport) + 1];
	strcpy(nazwisko, other.nazwisko);
	strcpy(sport, other.sport);
	waga = other.waga;
	ile++;
}

Sportowiec& Sportowiec::operator=(const Sportowiec& other)
{
	if (&other == this) {
		return *this;
	}

	delete[] sport;
	delete[] nazwisko;

	sport = new char[strlen(other.sport) + 1];
	nazwisko = new char[strlen(other.nazwisko) + 1];
	strcpy(sport, other.sport);
	strcpy(nazwisko, other.nazwisko);
	waga = other.waga;

	return *this;
}

int Sportowiec::getIle()
{
	return ile;
}

void Sportowiec::setWaga(const int& _waga)
{
	waga = _waga;
}

void Sportowiec::setNazwisko(const char* _nazwisko)
{
	delete[] nazwisko;
	nazwisko = new char[strlen(_nazwisko) + 1];
	strcpy(nazwisko, _nazwisko);
}

void Sportowiec::setSport(const char* _sport)
{
	delete[] sport;
	sport = new char[strlen(_sport) + 1];
	strcpy(sport, _sport);
}

std::ostream& operator<<(std::ostream& out, const Sportowiec& sportowiec)
{
	out << "Sport: " << sportowiec.nazwisko << "\n";
	out << "Nazwisko: " << sportowiec.sport << "\n";
	out << "Waga: " << sportowiec.waga << "\n";

	return out;
}

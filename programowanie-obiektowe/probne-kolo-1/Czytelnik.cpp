#include "Czytelnik.h"

Czytelnik::~Czytelnik()
{
    for (auto ksiazka : wypozyczone) delete ksiazka;
}

Czytelnik::Czytelnik(const Czytelnik& other)
{
    for (auto ksiazka : other.wypozyczone) {
        Ksiazka* nowa = ksiazka->clone();
        wypozyczone.push_back(nowa);
    }
}

Czytelnik& Czytelnik::operator+(Ksiazka* _ksiazka)
{
    wypozyczone.push_back(_ksiazka);
    return *this;
}

void Czytelnik::print(std::ostream& out)
{
    for (auto ksiazka : wypozyczone)
       ksiazka->print(out);
}

Ksiazka& Czytelnik::operator[](int i)
{
    return *wypozyczone[i];
}

void Czytelnik::zwroc(const std::string& _name)
{
    auto found = std::find_if(wypozyczone.begin(), wypozyczone.end(), [_name](Ksiazka* k) { return k->get_name() == _name; });
    if(found != wypozyczone.end())
        wypozyczone.erase(found);
}

Czytelnik Czytelnik::wybraneKsiazki(Gatunki gatunek) const
{
    Czytelnik nowy_czytelnik;

    for (auto ksiazka : wypozyczone) {
        switch (gatunek) {
        case Gatunki::Fikcja:
            if (Fikcja* f_ksiazka = dynamic_cast<Fikcja*>(ksiazka)) nowy_czytelnik + f_ksiazka->clone();
            break;

        case Gatunki::Podroze:
            if (Podroze* p_ksiazka = dynamic_cast<Podroze*>(ksiazka)) nowy_czytelnik + p_ksiazka->clone();
            break;
        }
    }

    return std::move(nowy_czytelnik);
}

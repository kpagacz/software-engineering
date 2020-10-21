#ifndef PRODUKT
#define PRODUKT
#include<string>

class Produkt {
    private:
        // pola klasowe
        string nazwa;
        float cena;
        bool czyZawieraGluten;

    public:
    // konstruktor z lista inicjalizacyjna
        Produkt(string n, float c, bool cz) : nazwa(n), cena(c), czyZawieraGluten(cz) {};
    // konstruktor bezparametrowy
        Produkt() : nazwa(""), cena(0), czyZawieraGluten(false) {};
    // destruktor
        virtual ~Produkt();

        void setName(string n) {
            name = n;
        }

        std::string getName() {
            return name;
        }
}

#endif PRODUKT // PRODUKT
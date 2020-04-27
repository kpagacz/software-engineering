#include <iostream>

struct Ulamek {
    private:
        int _licznik;
        int _mianownik;
        bool znak;
    public:
        Ulamek(int licznik = 0, int mianownik = 1);
        void Wypisz();
        void SkrocUlamek();

        // settery i gettery
        int getMianownik();
        void setMianownik(int mianownik);
        int getLicznik();
        void setLicznik(int licznik);

        // relational operators
        friend bool operator<(const Ulamek& l, const Ulamek& r);
        friend bool operator>(const Ulamek& l, const Ulamek& r);
        friend bool operator>=(const Ulamek& l, const Ulamek& r);
        friend bool operator<=(const Ulamek& l, const Ulamek& r);   
};




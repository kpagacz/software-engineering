#ifndef __PLIK
#define __PLIK

class Katalog{
    private:
        class Plik{
            public:
                const char* nazwa;
                unsigned int rozmiar;
                bool czy_ukryty;
                Plik* next_plik;
                Plik(const char* _nazwa, unsigned int _rozmiar, bool _czy_ukryty): 
                    nazwa(_nazwa), rozmiar(_rozmiar), czy_ukryty(_czy_ukryty), next_plik(nullptr) {};
                Plik(const char* _nazwa, unsigned int _rozmiar): 
                    nazwa(_nazwa), rozmiar(_rozmiar), czy_ukryty(false), next_plik(nullptr) {};
        };
        Plik* _head;

        void empty();

    public:
        // constructors, assignment, destructor
        Katalog(): _head(nullptr) {};
        Katalog(const Katalog&);
        Katalog(Katalog&&);

        Katalog& operator=(const Katalog&);
        Katalog& operator=(Katalog&&);

        ~Katalog();

        // other
        void dodaj_plik(const Plik&);
        void kopiuj(const Katalog&);

        Plik get_plik(const char*, unsigned int);
        void print() const;
};


#endif
class Macierz {
    public:
        // constructors
        Macierz(int wiersze, int kolumny, float wypelnienie = 0);

        // pobieranie i wypisywanie macierzy
        void PobierzMacierz();
        void WypiszMacierz() const;

        // zwrocenie elementu z konkretnego wiersza i konkretnej kolumny
        float Element(int wiersz, int kolumna) const;

        // algebra na macierzach
        friend Macierz operator+(const Macierz& l, const Macierz& p);
        friend Macierz operator-(const Macierz& l, const Macierz& p);
        friend Macierz operator*(const Macierz& l, const Macierz& p);
        friend Macierz operator*(const float& scalar, const Macierz& p);

        // transpozycja
        Macierz Transponuj() const;

        // gettery
        int getWiersze() const;
        int getKolumny() const;

        // settery
        void setElementAtIndex(int index, float value);
    private:
        int wiersze_;
        int kolumny_;
        float* macierz_;
};
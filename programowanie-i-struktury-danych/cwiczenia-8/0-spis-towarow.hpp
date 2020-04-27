#ifndef SPIS_TOWAROW
#define SPIS_TOWAROW

class Spis_towarow {
    private:
        struct Towar {
            friend class Spis_towarow;
            int kod_towaru;
            float ilosc;
            Towar* next_towar;
            // Towar(): kod_towaru(1), ilosc(0), next_towar(nullptr) {};
            Towar(int _kod_towaru, float _ilosc);
        };
    Towar* _head;
    Towar* _tail;
    std::size_t _size;

    void usunTowar(Towar*& pred_node, Towar*& current_node);
    int zliczIlosc(Towar* begin_counting, Towar* end_counting);

    public:
        void print() const;
        void wstaw(const Towar&);
        void wstaw_roznowartosciowo(const Towar&);
        void odejmij_ze_spisu(const Spis_towarow&);
        void skompresuj();

        Towar zrob_towar(int _kod_towaru, float _ilosc);

        // constructors
        Spis_towarow(): _head(nullptr), _tail(nullptr), _size(0) {};
        Spis_towarow(const Towar&);
        Spis_towarow(const Spis_towarow&);
        Spis_towarow(Spis_towarow&&);
        ~Spis_towarow();

        Spis_towarow& operator=(const Spis_towarow&);
        Spis_towarow& operator=(Spis_towarow&&);
        

};


#endif 
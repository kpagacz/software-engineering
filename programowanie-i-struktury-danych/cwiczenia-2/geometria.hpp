class Punkt {
    public:
        // constructor
        Punkt(int x = 0, int y = 0);

        // getters and setters
        int GetX() const;
        int GetY() const;
        void SetX(int x);
        void SetY(int y);

        // printing
        void Print() const;

    private:
        int _x;
        int _y;
};

class Prosta {
    public:
        // constructors
        Prosta(int a = 1, int b = 0);
        Prosta(const Punkt& point1, const Punkt& point2);

        // getters and setters
        int GetA() const;
        int GetB() const;
        void SetA(int a);
        void SetB(int b);

        // printing
        void Print() const;

    private:
        int _a;
        int _b;
};

bool isPointOnLine(const Punkt& point, const Prosta& line);